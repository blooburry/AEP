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
            painter.drawLine(x_coordinaat, y_coordinaat, x_coordinaat+lengte, y_coordinaat);
        } else {
            painter.drawLine(x_coordinaat, y_coordinaat - lengte, x_coordinaat, y_coordinaat);
        }
    } else {
        if(isDeurOpen()) {
            painter.drawLine(x_coordinaat, y_coordinaat, x_coordinaat, y_coordinaat+lengte);
        } else {
            painter.drawLine(x_coordinaat, y_coordinaat, x_coordinaat+lengte, y_coordinaat);
        }
    }
}
