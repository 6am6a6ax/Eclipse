#include "MaterialsWithPriceOver.h"
#include "ui_MaterialsWithPriceOver.h"

QSqlQueryModel *MaterialsWithPriceOver::selectData() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("MaterialsWithPriceOver.sql"),
                QVariantList({m_ui->spinBoxPrice->text()}),
                QVariantList({"Наименование",
                              "Общая стоимость"}));
}
