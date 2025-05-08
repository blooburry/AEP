#include "draaideur.h"

#include <QDebug>
#include <QPainter>

Draaideur::Draaideur(int x, int y, unsigned int l, bool liggend): Deur(x, y, l), liggend(liggend) {}

void Draaideur::teken(QPaintDevice* device) {
    if (!device) return;

    QPainter painter(device);
    painter.setPen(QPen(Qt::black, 4));

    if(liggend) {
        if(isDeurOpen()) {
            painter.drawLine(getX(), getY() - getLen(), getX(), getY());
        } else {
            painter.drawLine(getX(), getY(), getX()+getLen(), getY());
        }
    } else {
        if(isDeurOpen()) {
            painter.drawLine(getX(), getY(), getX()+getLen(), getY());
        } else {
            painter.drawLine(getX(), getY(), getX(), getY()+getLen());
        }
    }
}
