#ifndef PRODUCERS_H
#define PRODUCERS_H

#include <QMenu>
#include <QWidget>

#include "FileSql.h"
#include "DatabaseMssql.h"

namespace Ui { class Producers; }

class Producers : public QWidget
{
    Q_OBJECT
public:
    explicit Producers(QWidget *parent = nullptr);
    ~Producers();
signals:
    void statusChanged(const QString &status) const;
private slots:
    void setStatus(const QString &status) const;

    void callContextMenu(const QPoint& position);

    void on_pushButtonItemInsert_clicked();
    void on_pushButtonItemUpdate_clicked();
    void on_pushButtonItemUpdateCancel_clicked();

    void on_actionItemUpdate_triggered();
    void on_actionItemDelete_triggered();
private:
    Ui::Producers *m_ui;

    QMenu *m_menu;
    uint8_t m_selectedItemIndex;

    QSqlQueryModel *selectData() const;
    QSqlQuery *selectItem() const;

    QSqlQuery *insertItem() const;
    QSqlQuery *updateItem() const;
    QSqlQuery *deleteItem() const;
};

#endif // PRODUCERS_H
