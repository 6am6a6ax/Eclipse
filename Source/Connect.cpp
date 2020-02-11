#include "Connect.h"
#include "ui_Connect.h"

Connect::Connect(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::Connect())
{
    m_ui->setupUi(this);

    m_ui->lineEditPassword->setEchoMode(QLineEdit::Password);

    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);
}

Connect::~Connect()
{
    delete m_ui;
}

void Connect::on_pushButtonConnect_clicked()
{
    DatabaseMssql::getInstance().close();
    if (DatabaseMssql::getInstance().connect(
                m_ui->lineEditServerName->text(),
                "db_warehouse",
                m_ui->lineEditLogin->text(),
                m_ui->lineEditPassword->text()))
    {
        this->accept();
    }
    else
        QMessageBox::critical(this, this->windowTitle(), DatabaseMssql::getInstance().getDatabase().lastError().text());
}
