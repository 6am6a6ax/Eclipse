#ifndef MATERIALPOSITIONSBYNAME_H
#define MATERIALPOSITIONSBYNAME_H

#include <QWidget>
#include <QStringList>

#include "DatabaseMssql.h"
#include "FileSql.h"
#include "PrintWidget.h"

namespace Ui { class MaterialPositionsByName; }

class MaterialPositionsByName : public QWidget
{
    Q_OBJECT
public:
    explicit MaterialPositionsByName(QWidget *parent = nullptr);
    ~MaterialPositionsByName();
private slots:
    void on_pushButtonQuery_clicked();
    void on_pushButtonPrint_clicked();
private:
    Ui::MaterialPositionsByName *m_ui;

    QSqlQuery *selectMaterialsNames() const;
    QSqlQueryModel *selectData() const;

    void print();
};

#endif // MATERIALPOSITIONSBYNAME_H
