#ifndef PRINTWIDGET_H
#define PRINTWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPrinter>

class PrintWidget
{
    QPrinter *m_printer;
    QPainter *m_painter;
public:
    PrintWidget(const QPrinter::PrinterMode &printerMode = QPrinter::HighResolution);
    PrintWidget(const QPrinter::PrinterMode &printerMode,
                const QPrinter::OutputFormat &outputFormat);

    ~PrintWidget();

    void print(QWidget *widget, const QString &fileName);
};

#endif // PRINT_H
