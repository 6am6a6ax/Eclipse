#ifndef MATERIALSWITHPRICEOVER_H
#define MATERIALSWITHPRICEOVER_H

#include <QWidget>

#include "DatabaseMssql.h"
#include "FileSql.h"
#include "PrintWidget.h"

namespace Ui { class MaterialsWithPriceOver; }

class MaterialsWithPriceOver : public QWidget
{
    Q_OBJECT
public:
    explicit MaterialsWithPriceOver(QWidget *parent = nullptr);
    ~MaterialsWithPriceOver();
private slots:
    void on_pushButtonQuery_clicked();
    void on_pushButtonPrint_clicked();
private:
    Ui::MaterialsWithPriceOver *m_ui;

    QSqlQueryModel *selectData() const;
    void print();
};

#endif // MATERIALSWITHPRICEOVER_H
