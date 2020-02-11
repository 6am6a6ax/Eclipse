#include "Producers.h"
#include "ui_Producers.h"

QSqlQueryModel *Producers::selectData() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("Producers.sql"),
                QVariantList(),
                QVariantList({"Номер",
                              "Наименование",
                              "ИНН",
                              "Адрес",
                              "Телефон"}));
}

QSqlQuery *Producers::selectItem() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("Producer.sql"),
                QVariantList({m_selectedItemIndex}));
}

QSqlQuery *Producers::insertItem() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("ProducerInsert.sql"),
                QVariantList({m_ui->lineEditItemName->text(),
                              m_ui->lineEditItemTin->text(),
                              m_ui->lineEditItemAddress->text(),
                              m_ui->lineEditItemPhone->text()}));
}

QSqlQuery *Producers::updateItem() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("ProducerUpdate.sql"),
                QVariantList({m_ui->lineEditItemName->text(),
                              m_ui->lineEditItemTin->text(),
                              m_ui->lineEditItemAddress->text(),
                              m_ui->lineEditItemPhone->text(),
                              m_selectedItemIndex}));
}

QSqlQuery *Producers::deleteItem() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("ProducerDelete.sql"),
                QVariantList({m_selectedItemIndex}));
}
