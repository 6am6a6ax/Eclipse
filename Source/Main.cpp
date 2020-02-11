#include <QApplication>

#include "Connect.h"
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connect connect;
    if (connect.exec() != QDialog::Accepted)
        return 0;

    MainWindow w;
    w.show();
    return a.exec();
}
