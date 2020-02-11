#include "Incomes.h"
#include "ui_Incomes.h"

QSqlQuery *Incomes::selectMaterialsNames() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("MaterialsNames.sql"));
}

QSqlQuery *Incomes::selectResponsibleNames() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("ResponsibleNames.sql"));
}

QSqlQuery *Incomes::selectProducersNames() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("ProducersNames.sql"));
}

QSqlQuery *Incomes::selectPositions() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("Positions.sql"));
}

QSqlQueryModel *Incomes::selectData() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("Incomes.sql"),
                QVariantList(),
                QVariantList({"Номер",
                              "Дата поставки",
                              "Наименование",
                              "Количество",
                              "Единица измерения",
                              "Стоимость",
                              "Имя",
                              "Фамилия",
                              "Позиция",
                              "Поставщик",
                              "Адрес",
                              "Телефон",
                              "Ряд",
                              "Стеллаж"}));
}

QSqlQuery *Incomes::selectItem() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("Income.sql"),
                QVariantList({m_selectedItemIndex}));
}

QSqlQuery *Incomes::insertItem() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("IncomeInsert.sql"),
                QVariantList({m_ui->dateTimeEdit->text(),
                              m_ui->comboBoxMaterials->currentText(),
                              m_ui->spinBoxItemCount->text(),
                              m_ui->comboBoxResponsible->currentText().split(QChar(32))[0],
                              m_ui->comboBoxResponsible->currentText().split(QChar(32))[1],
                              m_ui->comboBoxProducers->currentText(),
                              m_ui->comboBoxPositions->currentText().split(QChar(45))[0],
                              m_ui->comboBoxPositions->currentText().split(QChar(45))[1]}));
}

QSqlQuery *Incomes::updateItem() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("IncomeUpdate.sql"),
                QVariantList({m_ui->dateTimeEdit->text(),
                              m_ui->comboBoxMaterials->currentText(),
                              m_ui->spinBoxItemCount->text(),
                              m_ui->comboBoxResponsible->currentText().split(QChar(32))[0],
                              m_ui->comboBoxResponsible->currentText().split(QChar(32))[1],
                              m_ui->comboBoxProducers->currentText(),
                              m_ui->comboBoxPositions->currentText().split(QChar(45))[0],
                              m_ui->comboBoxPositions->currentText().split(QChar(45))[1],
                              m_selectedItemIndex}));
}

QSqlQuery *Incomes::deleteItem() const
{
    return DatabaseMssql::getInstance().query(
                FileSql::getInstance().read("IncomeDelete.sql"),
                QVariantList({m_selectedItemIndex}));
}
