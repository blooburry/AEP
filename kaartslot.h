#ifndef KAARTSLOT_H
#define KAARTSLOT_H

#include "ISlot.h"
#include <string>
#include <map>
#include "idkaart.h"

using std::map;
using std::string;

class KaartSlot : public Slot {
private:
    string plaats;
    bool vergrendeld;
    static map<string, IdKaart*> idKaarten;  // Static map

public:
    KaartSlot(const string& plaats);
    void vergrendel() override;
    bool isVergrendeld() const override;
    void ontgrendel(string sleutel) override;
    static void voegIdKaartToe(IdKaart* eenIdKaart);
    static void verwijderIdKaart(const string& eenId);
    void geefIdKaartToegang(const string& id);
    void verwijderIdKaartToegang(const string& id);
};

#endif // KAARTSLOT_H
