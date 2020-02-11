#include "MaterialsWithPriceOver.h"
#include "ui_MaterialsWithPriceOver.h"

void MaterialsWithPriceOver::print()
{
    PrintWidget().print(this,
                        "Материалы на балансе со стоимостью выше " +
                        m_ui->spinBoxPrice->text() +
                        ".pdf");
}
