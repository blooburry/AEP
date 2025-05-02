#include "schuifdeur.h"
#include <QPaintDevice>
#include <QPainter>

Schuifdeur::Schuifdeur(int x, int y, unsigned int l, Sensor* s) : Deur(x, y, l), sensor(s) {
    status = false;
}

void Schuifdeur::sluit() {
    if(!(sensor->isGeactiveerd())) Deur::sluit();
}

void Schuifdeur::teken(QPaintDevice* device) {
    if (!device) return;

    QPainter painter(device);
    painter.setPen(QPen(Qt::black, 4));

    int x = x_coordinaat;
    int y = y_coordinaat;
    unsigned int l = lengte;

    int offset = isDeurOpen() ? l : 0;

    painter.drawLine(x, y + offset, x, y + offset + l);
}
