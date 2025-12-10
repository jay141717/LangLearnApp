#ifndef FRAGMENT_H
#define FRAGMENT_H

#include <QString>

// Abstract base class for a generic language fragment
class Fragment
{
public:
    QString spanish;
    QString english;

    Fragment(const QString &es = "", const QString &en = "")
        : spanish(es), english(en) {}

    // PURE VIRTUAL → makes Fragment an ABSTRACT class
    virtual QString info() const = 0;

    virtual ~Fragment() {}
};

#endif // FRAGMENT_H
