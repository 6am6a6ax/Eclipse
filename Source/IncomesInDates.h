#ifndef INCOMESINDATES_H
#define INCOMESINDATES_H

#include <QWidget>

#include "DatabaseMssql.h"
#include "FileSql.h"
#include "PrintWidget.h"

namespace Ui { class IncomesInDates; }

class IncomesInDates : public QWidget
{
    Q_OBJECT
public:
    explicit IncomesInDates(QWidget *parent = nullptr);
    ~IncomesInDates();
private slots:
    void on_pushButtonQuery_clicked();
    void on_pushButtonPrint_clicked();
private:
    Ui::IncomesInDates *m_ui;

    QSqlQueryModel *selectData() const;
    void print();
};

#endif // INCOMESINDATES_H
