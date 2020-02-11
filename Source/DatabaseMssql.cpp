#include "DatabaseMssql.h"

void DatabaseMssql::setStatus(const QString &status) const
{
    emit statusChanged(status);
}

QSqlDatabase DatabaseMssql::getDatabase() const
{
    return m_database;
}
