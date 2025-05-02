#ifndef DRAAIDEUR_H
#define DRAAIDEUR_H

#include "deur.h"

class Draaideur: public Deur {
private:
    bool liggend;
    int x;
    int y;
public:
    Draaideur(int, int, unsigned int, bool);
    void teken(QPaintDevice*) override;
};

#endif // DRAAIDEUR_H
