#include "Releases.h"
#include "ui_Releases.h"

QSqlQuery *Releases::selectMaterialsNames() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("MaterialsNames.sql"));
}

QSqlQueryModel *Releases::selectData() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("Releases.sql"),
                QVariantList(),
                QVariantList({"Номер",
                              "Дата выпуска",
                              "Наименование",
                              "Единица измерения",
                              "Стоимость",
                              "Количество"}));
}

QSqlQuery *Releases::selectItem() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("Release.sql"),
                QVariantList({m_selectedItemIndex}));
}

QSqlQuery *Releases::insertItem() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("ReleaseInsert.sql"),
                QVariantList({m_ui->dateTimeEdit->text(),
                              m_ui->comboBoxMaterials->currentText(),
                              m_ui->spinBoxItemCount->text()}));
}

QSqlQuery *Releases::updateItem() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("ReleaseUpdate.sql"),
                QVariantList({m_ui->dateTimeEdit->text(),
                              m_ui->comboBoxMaterials->currentText(),
                              m_ui->spinBoxItemCount->text(),
                              m_selectedItemIndex}));
}

QSqlQuery *Releases::deleteItem() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("ReleaseDelete.sql"),
                QVariantList({m_selectedItemIndex}));
}
