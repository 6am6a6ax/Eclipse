#include "MaterialsWithPriceOver.h"
#include "ui_MaterialsWithPriceOver.h"

MaterialsWithPriceOver::MaterialsWithPriceOver(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::MaterialsWithPriceOver())
{
    m_ui->setupUi(this);
    m_ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MaterialsWithPriceOver::~MaterialsWithPriceOver()
{
    delete m_ui;
}

void MaterialsWithPriceOver::on_pushButtonQuery_clicked()
{
    m_ui->tableView->setModel(selectData());
}

void MaterialsWithPriceOver::on_pushButtonPrint_clicked()
{
    print();
}
