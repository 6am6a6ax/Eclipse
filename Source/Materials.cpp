#include "Materials.h"

void Materials::setStatus(const QString &status) const
{
    emit statusChanged(status);
}
