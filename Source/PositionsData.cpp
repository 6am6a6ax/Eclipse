#include "Positions.h"
#include "ui_Positions.h"

QSqlQueryModel *Positions::selectData() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("Positions.sql"),
                QVariantList(),
                QVariantList({"Номер",
                              "Ряд",
                              "Стеллаж"}));
}

QSqlQuery *Positions::selectItem() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("Position.sql"),
                QVariantList({m_selectedItemIndex}));
}

QSqlQuery *Positions::insertItem() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("PositionInsert.sql"),
                QVariantList({m_ui->spinBoxItemRow->text(),
                              m_ui->spinBoxItemRack->text()}));
}

QSqlQuery *Positions::updateItem() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("PositionUpdate.sql"),
                QVariantList({m_ui->spinBoxItemRow->text(),
                              m_ui->spinBoxItemRack->text(),
                              m_selectedItemIndex}));
}

QSqlQuery *Positions::deleteItem() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("PositionDelete.sql"),
                QVariantList({m_selectedItemIndex}));
}
