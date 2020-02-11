#ifndef DATABASEMSSQL_H
#define DATABASEMSSQL_H

#include <QObject>
#include <QVariant>
#include <QVariantList>

#include <QtSql>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>

class DatabaseMssql : public QObject
{
    Q_OBJECT
public:
    static DatabaseMssql &getInstance()
    {
        static DatabaseMssql database;
        return database;
    }

    bool connect(const QString &serverName,
                 const QString &databaseName,
                 const QString &login,
                 const QString &password);

    void close();

    QSqlQuery *query(const QString &query,
                     const QVariantList &values = QVariantList()) const;

    QSqlQueryModel *query(const QString &query,
                          const QVariantList &values,
                          const QVariantList &headers) const;

    QSqlDatabase getDatabase() const;
signals:
    void statusChanged(const QString &status) const;
private slots:
    void setStatus(const QString &status) const;
private:
    DatabaseMssql() {}
    DatabaseMssql(DatabaseMssql const&) = delete;

    ~DatabaseMssql() {}

    const DatabaseMssql &operator=(DatabaseMssql const&) const = delete;

    QSqlDatabase m_database;
};

#endif // DATABASEMSSQL_H
