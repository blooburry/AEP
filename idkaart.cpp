#include "IdKaart.h"
#include "KaartSlot.h"  // Nodig voor de forward-declared KaartSlot

// Constructor
IdKaart::IdKaart(const string& id, const string& naam, const string& adres)
    : id(id), naamEigenaar(naam), adresEigenaar(adres) {}

// Getter voor de user ID
string IdKaart::userId() const {
    return id;
}

// Voeg toegang toe aan een KaartSlot
void IdKaart::geefToegang(KaartSlot* eenKaartSlot) {
    if (eenKaartSlot != nullptr) {
        toegang.push_back(eenKaartSlot);
    }
}

// Verwijder toegang van een KaartSlot
void IdKaart::verwijderToegang(KaartSlot* eenKaartSlot) {
    for (auto it = toegang.begin(); it != toegang.end(); ++it) {
        if (*it == eenKaartSlot) {
            toegang.erase(it);
            break;
        }
    }
}

// Controleer of er toegang is tot een bepaald KaartSlot
bool IdKaart::heeftToegangTot(KaartSlot* eenKaartSlot) const {
    for (auto slot : toegang) {
        if (slot == eenKaartSlot) {
            return true;
        }
    }
    return false;
}
