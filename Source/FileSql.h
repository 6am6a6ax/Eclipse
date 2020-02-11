#ifndef FILESQL_H
#define FILESQL_H

#include <QFile>
#include <QTextStream>
#include <QCoreApplication>

class FileSql
{
public:
    static const FileSql &getInstance()
    {
        static FileSql fileSql;
        return fileSql;
    }

    const QString read(const QString &fileName) const;
private:
    FileSql() {}
    FileSql(FileSql const&) = delete;

    ~FileSql() {}

    const FileSql &operator=(FileSql const&) const = delete;
};

#endif // FILESQL_H
