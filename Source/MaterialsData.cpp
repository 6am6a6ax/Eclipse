#include "Materials.h"
#include "ui_Materials.h"

QSqlQueryModel *Materials::selectData() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("Materials.sql"),
                QVariantList(),
                QVariantList({"Номер",
                              "Наименование",
                              "Единица измерения",
                              "Стоимость"}));
}

QSqlQuery *Materials::selectItem() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("Material.sql"),
                QVariantList({m_selectedItemIndex}));
}

QSqlQuery *Materials::insertItem() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("MaterialInsert.sql"),
                QVariantList({m_ui->lineEditItemName->text(),
                              m_ui->comboBoxUnits->currentText(),
                              m_ui->spinBoxItemPrice->text()}));
}

QSqlQuery *Materials::updateItem() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("MaterialUpdate.sql"),
                QVariantList({m_ui->lineEditItemName->text(),
                              m_ui->comboBoxUnits->currentText(),
                              m_ui->spinBoxItemPrice->text(),
                              m_selectedItemIndex}));
}

QSqlQuery *Materials::deleteItem() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("MaterialDelete.sql"),
                QVariantList({m_selectedItemIndex}));
}
