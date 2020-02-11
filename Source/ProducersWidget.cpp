#include "Producers.h"
#include "ui_Producers.h"

Producers::Producers(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::Producers()),
    m_menu(new QMenu(this))
{
    m_ui->setupUi(this);

    m_ui->pushButtonItemUpdate->hide();
    m_ui->pushButtonItemUpdateCancel->hide();

    m_ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    m_ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    m_ui->tableView->setModel(selectData());

    QAction *actionUpdateItem = new QAction("Изменить поставщика", this);
    connect(actionUpdateItem, SIGNAL(triggered()), this, SLOT(on_actionItemUpdate_triggered()));
    m_menu->addAction(actionUpdateItem);

    QAction *actionDeleteItem = new QAction("Удалить поставщика", this);
    connect(actionDeleteItem, SIGNAL(triggered()), this, SLOT(on_actionItemDelete_triggered()));
    m_menu->addAction(actionDeleteItem);

    connect(m_ui->tableView, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(callContextMenu(const QPoint&)));
}

Producers::~Producers()
{
    delete m_menu;
    delete m_ui;
}

void Producers::callContextMenu(const QPoint &position)
{
    m_selectedItemIndex = uint8_t(m_ui->tableView->model()->data(m_ui->tableView->model()->index(
                                                                     m_ui->tableView->indexAt(position).row(), 0)).toUInt());

    m_menu->popup(m_ui->tableView->viewport()->mapToGlobal(position));
}

void Producers::on_pushButtonItemInsert_clicked()
{
    if (insertItem())
    {
        m_ui->tableView->setModel(selectData());
        setStatus("Поставщик добавлен успешно.");
    }

    on_pushButtonItemUpdateCancel_clicked();
}

void Producers::on_pushButtonItemUpdate_clicked()
{
    if (updateItem())
    {
        m_ui->tableView->setModel(selectData());
        setStatus("Поставщик обновлен успешно.");
    }

    on_pushButtonItemUpdateCancel_clicked();
}

void Producers::on_pushButtonItemUpdateCancel_clicked()
{
    m_ui->lineEditItemName->clear();
    m_ui->lineEditItemTin->clear();
    m_ui->lineEditItemAddress->clear();
    m_ui->lineEditItemPhone->clear();
    m_ui->pushButtonItemUpdate->hide();
    m_ui->pushButtonItemUpdateCancel->hide();
    m_ui->pushButtonItemInsert->show();
    m_ui->tableView->setEnabled(true);
}

void Producers::on_actionItemUpdate_triggered()
{
    if (QSqlQuery *result = selectItem())
    {
        result->next();

        m_ui->tableView->setEnabled(false);
        m_ui->lineEditItemName->setText(result->value(1).toString());
        m_ui->lineEditItemTin->setText(result->value(2).toString());
        m_ui->lineEditItemAddress->setText(result->value(3).toString());
        m_ui->lineEditItemPhone->setText(result->value(4).toString());
        m_ui->pushButtonItemInsert->hide();
        m_ui->pushButtonItemUpdate->show();
        m_ui->pushButtonItemUpdateCancel->show();
    }
}

void Producers::on_actionItemDelete_triggered()
{
    if (deleteItem())
    {
        m_ui->tableView->setModel(selectData());
        setStatus("Поставщик удален успешно.");
    }
}
