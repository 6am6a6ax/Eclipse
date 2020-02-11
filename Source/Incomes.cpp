#include "Incomes.h"

void Incomes::setStatus(const QString &status) const
{
    emit statusChanged(status);
}
