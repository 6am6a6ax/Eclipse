#ifndef RELEASES_H
#define RELEASES_H

#include <QMenu>
#include <QWidget>

#include "FileSql.h"
#include "DatabaseMssql.h"

namespace Ui { class Releases; }

class Releases : public QWidget
{
    Q_OBJECT
public:
    explicit Releases(QWidget *parent = nullptr);
    ~Releases();
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
    Ui::Releases *m_ui;

    QMenu *m_menu;
    uint8_t m_selectedItemIndex;

    QSqlQuery *selectMaterialsNames() const;

    QSqlQueryModel *selectData() const;
    QSqlQuery *selectItem() const;

    QSqlQuery *insertItem() const;
    QSqlQuery *updateItem() const;
    QSqlQuery *deleteItem() const;
};

#endif // RELEASES_H
