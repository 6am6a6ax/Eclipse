#include "Releases.h"
#include "ui_Releases.h"

Releases::Releases(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::Releases()),
    m_menu(new QMenu(this))
{
    m_ui->setupUi(this);

    m_ui->pushButtonItemUpdate->hide();
    m_ui->pushButtonItemUpdateCancel->hide();

    m_ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    m_ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    m_ui->tableView->setModel(selectData());

    QAction *actionUpdateItem = new QAction("Изменить выпуск", this);
    connect(actionUpdateItem, SIGNAL(triggered()), this, SLOT(on_actionItemUpdate_triggered()));
    m_menu->addAction(actionUpdateItem);

    QAction *actionDeleteItem = new QAction("Удалить выпуск", this);
    connect(actionDeleteItem, SIGNAL(triggered()), this, SLOT(on_actionItemDelete_triggered()));
    m_menu->addAction(actionDeleteItem);

    connect(m_ui->tableView, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(callContextMenu(const QPoint&)));

    m_ui->comboBoxMaterials->addItems([&]() -> QStringList {
                                          QStringList result = QStringList();

                                          QSqlQuery query = *selectMaterialsNames();
                                          while (query.next())
                                            result.push_back(query.value(0).toString());

                                          return result;
                                      }());
}

Releases::~Releases()
{
    delete m_menu;
    delete m_ui;
}

void Releases::callContextMenu(const QPoint &position)
{
    m_selectedItemIndex = uint8_t(m_ui->tableView->model()->data(m_ui->tableView->model()->index(
                                                                     m_ui->tableView->indexAt(position).row(), 0)).toUInt());

    m_menu->popup(m_ui->tableView->viewport()->mapToGlobal(position));
}

void Releases::on_pushButtonItemInsert_clicked()
{
    if (insertItem())
    {
        m_ui->tableView->setModel(selectData());
        setStatus("Выпуск добавлен успешно.");
    }

    on_pushButtonItemUpdateCancel_clicked();
}

void Releases::on_pushButtonItemUpdate_clicked()
{
    if (updateItem())
    {
        m_ui->tableView->setModel(selectData());
        setStatus("Выпуск обновлен успешно.");
    }

    on_pushButtonItemUpdateCancel_clicked();
}

void Releases::on_pushButtonItemUpdateCancel_clicked()
{
    m_ui->dateTimeEdit->clear();
    m_ui->comboBoxMaterials->setCurrentIndex(0);
    m_ui->spinBoxItemCount->clear();

    m_ui->pushButtonItemUpdate->hide();
    m_ui->pushButtonItemUpdateCancel->hide();
    m_ui->pushButtonItemInsert->show();

    m_ui->tableView->setEnabled(true);
}

void Releases::on_actionItemUpdate_triggered()
{
    if (QSqlQuery *result = selectItem())
    {
        result->next();

        m_ui->tableView->setEnabled(false);

        m_ui->dateTimeEdit->setDateTime(result->value(0).toDateTime());
        m_ui->comboBoxMaterials->setCurrentIndex(m_ui->comboBoxMaterials->findText(
                                                     result->value(1).toString()));

        m_ui->spinBoxItemCount->setValue(result->value(2).toInt());

        m_ui->pushButtonItemInsert->hide();
        m_ui->pushButtonItemUpdate->show();
        m_ui->pushButtonItemUpdateCancel->show();
    }
}

void Releases::on_actionItemDelete_triggered()
{
    if (deleteItem())
    {
        m_ui->tableView->setModel(selectData());
        setStatus("Выпуск удален успешно.");
    }
}
