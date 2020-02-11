#include "Producers.h"

void Producers::setStatus(const QString &status) const
{
    emit statusChanged(status);
}
