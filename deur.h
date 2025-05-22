#ifndef DEUR_H
#define DEUR_H

#include <memory>
#include "ISlot.h"
#include <string>
#include <vector>

using namespace std;


class QPaintDevice;

class Deur {
private:
    bool status = false;
    int x_coordinaat;
    int y_coordinaat;
    unsigned int lengte;
    vector<shared_ptr<Slot>> sloten;

public:
    Deur(int, int, unsigned int);
    void open();
    virtual void sluit();
    virtual void teken(QPaintDevice*)=0;
    void voegSlotToe(shared_ptr<Slot>);
    bool isDeurOpen() const;

    int getX() const;
    int getY() const;
    int getLen() const;
    vector<shared_ptr<Slot>> getSloten() const;
    void setStatus(bool);
    bool getStatus() const;
};

#endif // DEUR_H
