#include "MaterialPositionsByName.h"
#include "ui_MaterialPositionsByName.h"

void MaterialPositionsByName::print()
{
    PrintWidget().print(this,
                        "Расположение материала с указанным наименованием - " +
                        m_ui->comboBoxMaterials->currentText() +
                        ".pdf");
}
