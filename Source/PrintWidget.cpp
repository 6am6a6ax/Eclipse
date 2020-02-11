#include "PrintWidget.h"

PrintWidget::PrintWidget(const QPrinter::PrinterMode &printerMode)
{
    m_printer = new QPrinter(printerMode);
    m_printer->setOutputFormat(QPrinter::PdfFormat);
    m_printer->setFullPage(true);
}

PrintWidget::PrintWidget(const QPrinter::PrinterMode &printerMode,
                         const QPrinter::OutputFormat &outputFormat)
    : PrintWidget(printerMode)
{
    m_printer->setOutputFormat(outputFormat);
}

PrintWidget::~PrintWidget()
{
    delete m_painter;
    delete m_printer;
}

void PrintWidget::print(QWidget *widget, const QString &fileName)
{
    m_printer->setOutputFileName("reports/" + fileName);

    m_painter = new QPainter(m_printer);
    m_painter->translate(m_printer->paperRect().center());

    double scale = qMin(m_printer->pageRect().width() / double(widget->width()),
                        m_printer->pageRect().height() / double(widget->height()));

    m_painter->scale(scale, scale);
    m_painter->translate(-widget->width() / 2, -widget->height() / 2);

    widget->render(m_painter);
}


