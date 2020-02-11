#include "DatabaseMssql.h"

QSqlQuery *DatabaseMssql::query(const QString &query,
                                const QVariantList &values) const
{
    QSqlQuery *sqlQuery = new QSqlQuery();
    sqlQuery->prepare(query);

    for (uint8_t i = 0; i < values.count(); i++)
        sqlQuery->bindValue(i, values[i]);

    if (sqlQuery->exec())
    {
        setStatus("Запрос выполнен успешно.");
        return sqlQuery;
    }
    else
        setStatus("При выполнении запроса произошла ошибка: " +
                  sqlQuery->lastError().databaseText());

    delete sqlQuery;
    return nullptr;
}

QSqlQueryModel *DatabaseMssql::query(const QString &query,
                                     const QVariantList &values,
                                     const QVariantList &headers) const
{
    QSqlQuery *sqlQuery = new QSqlQuery();
    sqlQuery->prepare(query);

    for (uint8_t i = 0; i < values.count(); i++)
        sqlQuery->bindValue(i, values[i]);

    if (sqlQuery->exec())
    {
        QSqlQueryModel *sqlQueryModel = new QSqlQueryModel();
        sqlQueryModel->setQuery(*sqlQuery);
        delete sqlQuery;

        for (uint8_t i = 0; i < headers.count(); i++)
            sqlQueryModel->setHeaderData(i, Qt::Horizontal, headers[i]);

        setStatus("Запрос выполнен успешно.");

        return sqlQueryModel;
    }
    else
        setStatus("При выполнении запроса произошла ошибка: " +
                  sqlQuery->lastError().databaseText());

    delete sqlQuery;
    return nullptr;
}
