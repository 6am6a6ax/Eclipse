#include "Positions.h"

void Positions::setStatus(const QString &status) const
{
    emit statusChanged(status);
}
