#ifndef IAFDRUKKER_H
#define IAFDRUKKER_H

#include <string>

using namespace std;

class IAfdrukker {
public:
    virtual void toonTekst(string) const =0;
    virtual void clearMedium() =0;
    virtual ~IAfdrukker() = default;
};

#endif // IAFDRUKKER_H
