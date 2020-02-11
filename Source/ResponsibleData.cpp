#include "Responsible.h"
#include "ui_Responsible.h"

QSqlQueryModel *Responsible::selectData() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("Liable.sql"),
                QVariantList(),
                QVariantList({"Номер",
                              "Фамилия",
                              "Имя",
                              "Должность",
                              "Отчество"}));
}

QSqlQuery *Responsible::selectItem() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("Responsible.sql"),
                QVariantList({m_selectedItemIndex}));
}

QSqlQuery *Responsible::insertItem() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("ResponsibleInsert.sql"),
                QVariantList({m_ui->lineEditItemSurname->text(),
                              m_ui->lineEditItemFirstName->text(),
                              m_ui->comboBoxPositions->currentText(),
                              m_ui->lineEditItemLastName->text()}));
}

QSqlQuery *Responsible::updateItem() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("ResponsibleUpdate.sql"),
                QVariantList({m_ui->lineEditItemSurname->text(),
                              m_ui->lineEditItemFirstName->text(),
                              m_ui->comboBoxPositions->currentText(),
                              m_ui->lineEditItemLastName->text(),
                              m_selectedItemIndex}));
}

QSqlQuery *Responsible::deleteItem() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("ResponsibleDelete.sql"),
                QVariantList({m_selectedItemIndex}));
}
