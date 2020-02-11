#include "DatabaseMssql.h"

bool DatabaseMssql::connect(const QString &serverName,
                            const QString &databaseName,
                            const QString &login,
                            const QString &password)
{
    m_database = QSqlDatabase::addDatabase("QODBC3");
    m_database.setDatabaseName("DRIVER={SQL Server};"
                               "SERVER=" + serverName +
                               ";DATABASE=" + databaseName + ";");

    m_database.setUserName(login);
    m_database.setPassword(password);

    if (m_database.open())
    {
        setStatus("Соединение с базой данных успешно установлено.");
        return true;
    }
    else
        setStatus("Произошла ошибка при соединении с базой данных: " +
                  m_database.lastError().text());

    return false;
}

void DatabaseMssql::close()
{
    m_database.close();
}
