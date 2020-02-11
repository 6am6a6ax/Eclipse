#include "Materials.h"
#include "ui_Materials.h"

Materials::Materials(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::Materials()),
    m_menu(new QMenu(this))
{
    m_ui->setupUi(this);

    m_ui->pushButtonItemUpdate->hide();
    m_ui->pushButtonItemUpdateCancel->hide();

    m_ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    m_ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    m_ui->tableView->setModel(selectData());

    QAction *actionUpdateItem = new QAction("Изменить материал", this);
    connect(actionUpdateItem, SIGNAL(triggered()), this, SLOT(on_actionItemUpdate_triggered()));
    m_menu->addAction(actionUpdateItem);

    QAction *actionDeleteItem = new QAction("Удалить материал", this);
    connect(actionDeleteItem, SIGNAL(triggered()), this, SLOT(on_actionItemDelete_triggered()));
    m_menu->addAction(actionDeleteItem);

    connect(m_ui->tableView, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(callContextMenu(const QPoint&)));
}

Materials::~Materials()
{
    delete m_menu;
    delete m_ui;
}

void Materials::callContextMenu(const QPoint &position)
{
    m_selectedItemIndex = uint8_t(m_ui->tableView->model()->data(m_ui->tableView->model()->index(
                                                                     m_ui->tableView->indexAt(position).row(), 0)).toUInt());

    m_menu->popup(m_ui->tableView->viewport()->mapToGlobal(position));
}

void Materials::on_pushButtonItemInsert_clicked()
{
    if (insertItem())
    {
        m_ui->tableView->setModel(selectData());
        setStatus("Материал добавлен успешно.");
    }

    on_pushButtonItemUpdateCancel_clicked();
}

void Materials::on_pushButtonItemUpdate_clicked()
{
    if (updateItem())
    {
        m_ui->tableView->setModel(selectData());
        setStatus("Материал обновлен успешно.");
    }

    on_pushButtonItemUpdateCancel_clicked();
}

void Materials::on_pushButtonItemUpdateCancel_clicked()
{
    m_ui->lineEditItemName->clear();
    m_ui->comboBoxUnits->setCurrentIndex(0);
    m_ui->spinBoxItemPrice->clear();
    m_ui->pushButtonItemUpdate->hide();
    m_ui->pushButtonItemUpdateCancel->hide();
    m_ui->pushButtonItemInsert->show();
    m_ui->tableView->setEnabled(true);
}

void Materials::on_actionItemUpdate_triggered()
{
    if (QSqlQuery *result = selectItem())
    {
        result->next();

        m_ui->tableView->setEnabled(false);
        m_ui->lineEditItemName->setText(result->value(1).toString());
        m_ui->comboBoxUnits->setCurrentIndex(m_ui->comboBoxUnits->findText(result->value(2).toString()));
        m_ui->spinBoxItemPrice->setValue(result->value(3).toInt());
        m_ui->pushButtonItemInsert->hide();
        m_ui->pushButtonItemUpdate->show();
        m_ui->pushButtonItemUpdateCancel->show();
    }
}

void Materials::on_actionItemDelete_triggered()
{
    if (deleteItem())
    {
        m_ui->tableView->setModel(selectData());
        setStatus("Материал удален успешно.");
    }
}
