#include "Releases.h"

void Releases::setStatus(const QString &status) const
{
    emit statusChanged(status);
}
