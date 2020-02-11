#include "MaterialPositionsByName.h"
#include "ui_MaterialPositionsByName.h"

QSqlQuery *MaterialPositionsByName::selectMaterialsNames() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("MaterialsNames.sql"));
}

QSqlQueryModel *MaterialPositionsByName::selectData() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("MaterialPositionsByName.sql"),
                QVariantList({m_ui->comboBoxMaterials->currentText()}),
                QVariantList({"Дата поставки",
                              "Наименование",
                              "Количество",
                              "Ряд",
                              "Стеллаж"}));
}
