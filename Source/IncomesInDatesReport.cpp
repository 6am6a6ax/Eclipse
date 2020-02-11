#include "IncomesInDates.h"
#include "ui_IncomesInDates.h"

void IncomesInDates::print()
{
    PrintWidget().print(this,
                        "Поставки материалов в период с " +
                        m_ui->dateEditStartDate->text() +
                        " по " +
                        m_ui->dateEditEndDate->text() +
                        ".pdf");
}
