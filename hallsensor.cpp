#include "hallsensor.h"

#include <QPaintDevice>
#include <QPainter>
#include <QPen>

Hallsensor::Hallsensor(int x, int y): Sensor(x, y) { }

void Hallsensor::teken(QPaintDevice* tp) {
    QPainter p(tp);
    QColor kleur;
    p.setBrush(Qt::SolidPattern);
    if(geactiveerd)
        kleur=Qt::green;
    else
        kleur=Qt::white;

    p.setBrush(kleur);
    QPen pen(kleur,2,Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    p.setPen(pen);
    p.drawEllipse(x,y,20,20);
}
