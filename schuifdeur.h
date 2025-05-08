#ifndef SCHUIFDEUR_H
#define SCHUIFDEUR_H

#include "deur.h"
#include "sensor.h"
#include "slot.h"

class Schuifdeur : public Deur {
public:
    Schuifdeur(int, int, unsigned int, Sensor*);
    void teken(QPaintDevice*) override;
    void sluit() override;

private:
    Sensor* sensor;
};

#endif // SCHUIFDEUR_H
