#include "MaterialPositionsByName.h"
#include "ui_MaterialPositionsByName.h"

MaterialPositionsByName::MaterialPositionsByName(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::MaterialPositionsByName())
{
    m_ui->setupUi(this);
    m_ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    m_ui->comboBoxMaterials->addItems([&]() -> QStringList {
                                          QStringList result = QStringList();

                                          QSqlQuery materialsNames = *selectMaterialsNames();
                                          while (materialsNames.next())
                                            result.push_back(materialsNames.value(0).toString());

                                          return result;
                                      }());
}

MaterialPositionsByName::~MaterialPositionsByName()
{
    delete m_ui;
}

void MaterialPositionsByName::on_pushButtonQuery_clicked()
{
    m_ui->tableView->setModel(selectData());
}

void MaterialPositionsByName::on_pushButtonPrint_clicked()
{
    print();
}
