#include "kaartslot.h"
#include "slotexception.h"

using std::string;
using std::map;
using std::out_of_range;

map<string, IdKaart*> KaartSlot::idKaarten;

KaartSlot::KaartSlot(const string& plaats) : plaats(plaats), vergrendeld(true) {}

void KaartSlot::vergrendel() {
    vergrendeld = true;
}

bool KaartSlot::isVergrendeld() const {
    return vergrendeld;
}

void KaartSlot::ontgrendel(string sleutel) {
    try {
        if(idKaarten.at(sleutel)->heeftToegangTot(this)) {
            vergrendeld = false;
        } else {
            throw SlotException(sleutel, this->plaats);
        }
    } catch (const std::out_of_range& e) {
    qWarning() << "ID does not exist!";
}
}

void KaartSlot::voegIdKaartToe(IdKaart* eenIdKaart) {
    idKaarten[eenIdKaart->userId()] = eenIdKaart;
}

void KaartSlot::verwijderIdKaart(const string& eenId) {
    idKaarten.erase(eenId);
}

void KaartSlot::geefIdKaartToegang(const string& id) {
    try{
        idKaarten.at(id)->geefToegang(this);
    } catch (const std::out_of_range& e) {
        qWarning() << "ID does not exist!";
    }
}

void KaartSlot::verwijderIdKaartToegang(const string& id) {
    try{
        idKaarten.at(id)->verwijderToegang(this);
    } catch (const std::out_of_range& e) {
        qWarning() << "ID does not exist!";
    }
}
