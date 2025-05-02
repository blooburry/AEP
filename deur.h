#ifndef DEUR_H
#define DEUR_H

#include <utility>

using namespace std;


class QPaintDevice;

class Deur {
protected:
    bool status;
    int x_coordinaat;
    int y_coordinaat;
    unsigned int lengte;

public:
    Deur(int, int, unsigned int);
    void open();
    virtual void sluit();
    virtual void teken(QPaintDevice*);
    bool isDeurOpen();
    unsigned int deurLengte;
};

#endif // DEUR_H
