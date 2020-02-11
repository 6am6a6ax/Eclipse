#include "Responsible.h"
#include "ui_Responsible.h"

Responsible::Responsible(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::Responsible()),
    m_menu(new QMenu(this))
{
    m_ui->setupUi(this);

    m_ui->pushButtonItemUpdate->hide();
    m_ui->pushButtonItemUpdateCancel->hide();

    m_ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    m_ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    m_ui->tableView->setModel(selectData());

    QAction *actionUpdateItem = new QAction("Изменить ответственного", this);
    connect(actionUpdateItem, SIGNAL(triggered()), this, SLOT(on_actionItemUpdate_triggered()));
    m_menu->addAction(actionUpdateItem);

    QAction *actionDeleteItem = new QAction("Удалить ответственного", this);
    connect(actionDeleteItem, SIGNAL(triggered()), this, SLOT(on_actionItemDelete_triggered()));
    m_menu->addAction(actionDeleteItem);

    connect(m_ui->tableView, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(callContextMenu(const QPoint&)));
}

Responsible::~Responsible()
{
    delete m_menu;
    delete m_ui;
}

void Responsible::callContextMenu(const QPoint &position)
{
    m_selectedItemIndex = uint8_t(m_ui->tableView->model()->data(m_ui->tableView->model()->index(
                                                                     m_ui->tableView->indexAt(position).row(), 0)).toUInt());

    m_menu->popup(m_ui->tableView->viewport()->mapToGlobal(position));
}

void Responsible::on_pushButtonItemInsert_clicked()
{
    if (insertItem())
    {
        m_ui->tableView->setModel(selectData());
        setStatus("Ответственный добавлен успешно.");
    }

    on_pushButtonItemUpdateCancel_clicked();
}

void Responsible::on_pushButtonItemUpdate_clicked()
{
    if (updateItem())
    {
        m_ui->tableView->setModel(selectData());
        setStatus("Ответственный обновлен успешно.");
    }

    on_pushButtonItemUpdateCancel_clicked();
}

void Responsible::on_pushButtonItemUpdateCancel_clicked()
{
    m_ui->lineEditItemFirstName->clear();
    m_ui->lineEditItemSurname->clear();
    m_ui->lineEditItemLastName->clear();
    m_ui->comboBoxPositions->setCurrentIndex(0);
    m_ui->pushButtonItemUpdate->hide();
    m_ui->pushButtonItemUpdateCancel->hide();
    m_ui->pushButtonItemInsert->show();
    m_ui->tableView->setEnabled(true);
}

void Responsible::on_actionItemUpdate_triggered()
{
    if (QSqlQuery *result = selectItem())
    {
        result->next();

        m_ui->tableView->setEnabled(false);
        m_ui->lineEditItemSurname->setText(result->value(1).toString());
        m_ui->lineEditItemFirstName->setText(result->value(2).toString());
        m_ui->comboBoxPositions->setCurrentIndex(m_ui->comboBoxPositions->findText(result->value(3).toString()));
        m_ui->lineEditItemLastName->setText(result->value(4).toString());
        m_ui->pushButtonItemInsert->hide();
        m_ui->pushButtonItemUpdate->show();
        m_ui->pushButtonItemUpdateCancel->show();
    }
}

void Responsible::on_actionItemDelete_triggered()
{
    if (deleteItem())
    {
        m_ui->tableView->setModel(selectData());
        setStatus("Ответственный удален успешно.");
    }
}
