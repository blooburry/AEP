#ifndef IDKAART_H
#define IDKAART_H

#include <string>
#include <vector>

class KaartSlot;

using std::string;
using std::vector;

class IdKaart {
private:
    string id;
    vector<KaartSlot*> toegang;
    string naamEigenaar;
    string adresEigenaar;
public:
    IdKaart(const string&, const string&, const string&);
    string userId() const;
    void geefToegang(KaartSlot*);
    void verwijderToegang(KaartSlot*);
    bool heeftToegangTot(KaartSlot*) const;
};

#endif // IDKAART_H
