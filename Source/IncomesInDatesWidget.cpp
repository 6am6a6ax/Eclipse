#include "IncomesInDates.h"
#include "ui_IncomesInDates.h"

IncomesInDates::IncomesInDates(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::IncomesInDates())
{
    m_ui->setupUi(this);
    m_ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

IncomesInDates::~IncomesInDates()
{
    delete m_ui;
}

void IncomesInDates::on_pushButtonQuery_clicked()
{
    m_ui->tableView->setModel(selectData());
}

void IncomesInDates::on_pushButtonPrint_clicked()
{
    print();
}
