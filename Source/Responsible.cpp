#include "Responsible.h"

void Responsible::setStatus(const QString &status) const
{
    emit statusChanged(status);
}
