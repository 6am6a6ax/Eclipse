#include "IncomesInDates.h"
#include "ui_IncomesInDates.h"

QSqlQueryModel *IncomesInDates::selectData() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("IncomesInDates.sql"),
                QVariantList({m_ui->dateEditStartDate->text(),
                              m_ui->dateEditEndDate->text()}),
                QVariantList({"Дата поставки",
                              "Наименование",
                              "Количество",
                              "Имя",
                              "Фамилия",
                              "Поставщик",
                              "Ряд",
                              "Стеллаж"}));

}
