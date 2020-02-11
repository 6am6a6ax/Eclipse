#include "FileSql.h"

const QString FileSql::read(const QString &fileName) const
{
    QFile file(QCoreApplication::applicationDirPath() + "/queries/" + fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return QString();

    QTextStream in(&file);

    return in.readAll();
}
