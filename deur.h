#ifndef DEUR_H
#define DEUR_H

#include <memory>
#include "slot.h"
#include <string>

using namespace std;


class QPaintDevice;

class Deur {
protected:
    bool status;
    int x_coordinaat;
    int y_coordinaat;
    unsigned int lengte;
    shared_ptr<Slot> slot;

public:
    Deur(int, int, unsigned int, shared_ptr<Slot>);
    void open(string s);
    virtual void sluit();
    virtual void teken(QPaintDevice*);
    bool isDeurOpen();
    unsigned int deurLengte;
};

#endif // DEUR_H
