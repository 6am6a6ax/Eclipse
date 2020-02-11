#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QString>
#include <QMainWindow>

#include "Connect.h"
#include "About.h"

// Catalogs
#include "Materials.h"
#include "Positions.h"
#include "Responsible.h"
#include "Producers.h"
#include "Incomes.h"
#include "Releases.h"

// Reports
#include "IncomesInDates.h"
#include "MaterialsWithPriceOver.h"
#include "MaterialPositionsByName.h"

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *m_ui;
signals:
    void statusChanged(const QString &status) const;
private slots:
    void setStatus(const QString &status) const;

    void on_tabWidget_tabCloseRequested(int index);

    void on_actionAbout_triggered();

    // Catalogs
    void on_actionMaterials_triggered();
    void on_pushButtonMaterials_clicked();

    void on_actionPositions_triggered();
    void on_actionProducers_triggered();
    void on_actionResponsible_triggered();

    void on_actionIncomes_triggered();
    void on_pushButtonIncomes_clicked();

    void on_actionReleases_triggered();
    void on_pushButtonReleases_clicked();

    // Reports
    void on_actionIncomesInDates_triggered();
    void on_actionMaterialsWithPriceOver_triggered();
    void on_actionMaterialPositionsByName_triggered();
};

#endif // MAINWINDOW_H
