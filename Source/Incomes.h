#ifndef INCOMES_H
#define INCOMES_H

#include <QMenu>
#include <QWidget>

#include "FileSql.h"
#include "DatabaseMssql.h"

namespace Ui { class Incomes; }

class Incomes : public QWidget
{
    Q_OBJECT
public:
    explicit Incomes(QWidget *parent = nullptr);
    ~Incomes();
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
    Ui::Incomes *m_ui;

    QMenu *m_menu;
    uint8_t m_selectedItemIndex;

    QSqlQuery *selectMaterialsNames() const;
    QSqlQuery *selectResponsibleNames() const;
    QSqlQuery *selectProducersNames() const;
    QSqlQuery *selectPositions() const;

    QSqlQueryModel *selectData() const;
    QSqlQuery *selectItem() const;

    QSqlQuery *insertItem() const;
    QSqlQuery *updateItem() const;
    QSqlQuery *deleteItem() const;
};

#endif // INCOMES_H
