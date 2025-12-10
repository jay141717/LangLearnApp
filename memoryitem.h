#ifndef MEMORYITEM_H
#define MEMORYITEM_H

#include "fragment.h"

// Concrete subclass used by the app
class MemoryItem : public Fragment
{
public:
    bool known;

    MemoryItem(const QString &es = "", const QString &en = "", bool k = false)
        : Fragment(es, en), known(k) {}

    // Implements the abstract method from Fragment
    QString info() const override
    {
        return QString("MemoryItem: [%1] known=%2")
                .arg(spanish + " = " + english)
                .arg(known ? "true" : "false");
    }
};

#endif // MEMORYITEM_H
