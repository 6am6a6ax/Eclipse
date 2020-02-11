#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow())
{
    m_ui->setupUi(this);

    QAction *actionAbout = m_ui->menubar->addAction("О программе");
    connect(actionAbout, SIGNAL(triggered()), this, SLOT(on_actionAbout_triggered()));

    connect(&DatabaseMssql::getInstance(), SIGNAL(statusChanged(const QString&)), this, SLOT(setStatus(const QString&)));
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

void MainWindow::setStatus(const QString& status) const
{
    m_ui->statusbar->showMessage(status);
    emit statusChanged(status);
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    m_ui->tabWidget->removeTab(index);
}

void MainWindow::on_actionAbout_triggered()
{
    About *dialog = new About();
    dialog->show();
}

void MainWindow::on_actionMaterials_triggered()
{
    Materials *tab = new Materials();
    m_ui->tabWidget->addTab(tab, tab->windowTitle());

    connect(tab, SIGNAL(statusChanged(const QString&)), this, SLOT(setStatus(const QString&)));
}

void MainWindow::on_pushButtonMaterials_clicked()
{
    on_actionMaterials_triggered();
}

void MainWindow::on_actionPositions_triggered()
{
    Positions *tab = new Positions();
    m_ui->tabWidget->addTab(tab, tab->windowTitle());

    connect(tab, SIGNAL(statusChanged(const QString&)), this, SLOT(setStatus(const QString&)));
}

void MainWindow::on_actionProducers_triggered()
{
    Producers *tab = new Producers();
    m_ui->tabWidget->addTab(tab, tab->windowTitle());

    connect(tab, SIGNAL(statusChanged(const QString&)), this, SLOT(setStatus(const QString&)));
}

void MainWindow::on_actionResponsible_triggered()
{
    Responsible *tab = new Responsible();
    m_ui->tabWidget->addTab(tab, tab->windowTitle());

    connect(tab, SIGNAL(statusChanged(const QString&)), this, SLOT(setStatus(const QString&)));
}

void MainWindow::on_actionIncomes_triggered()
{
    Incomes *tab = new Incomes();
    m_ui->tabWidget->addTab(tab, tab->windowTitle());

    connect(tab, SIGNAL(statusChanged(const QString&)), this, SLOT(setStatus(const QString&)));
}

void MainWindow::on_pushButtonIncomes_clicked()
{
    on_actionIncomes_triggered();
}

void MainWindow::on_actionReleases_triggered()
{
    Releases *tab = new Releases();
    m_ui->tabWidget->addTab(tab, tab->windowTitle());

    connect(tab, SIGNAL(statusChanged(const QString&)), this, SLOT(setStatus(const QString&)));
}

void MainWindow::on_pushButtonReleases_clicked()
{
    on_actionReleases_triggered();
}

void MainWindow::on_actionIncomesInDates_triggered()
{
    IncomesInDates *tab = new IncomesInDates();
    m_ui->tabWidget->addTab(tab, tab->windowTitle());
}

void MainWindow::on_actionMaterialsWithPriceOver_triggered()
{
    MaterialsWithPriceOver *tab = new MaterialsWithPriceOver();
    m_ui->tabWidget->addTab(tab, tab->windowTitle());
}

void MainWindow::on_actionMaterialPositionsByName_triggered()
{
    MaterialPositionsByName *tab = new MaterialPositionsByName();
    m_ui->tabWidget->addTab(tab, tab->windowTitle());
}
