#include "About.h"
#include "ui_About.h"

About::About(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::About())
{
    m_ui->setupUi(this);

    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);
}

About::~About()
{
    delete m_ui;
}
