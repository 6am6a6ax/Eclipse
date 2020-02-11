#ifndef CONNECT_H
#define CONNECT_H

#include <QDialog>
#include <QMessageBox>

#include "DatabaseMssql.h"

namespace Ui { class Connect; }

class Connect : public QDialog
{
    Q_OBJECT

public:
    explicit Connect(QWidget *parent = nullptr);
    ~Connect() override;
private slots:
    void on_pushButtonConnect_clicked();
private:
    Ui::Connect *m_ui;
};

#endif // CONNECT_H
