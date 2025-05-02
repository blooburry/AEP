#include "deur.h"

#include <QPaintDevice>
#include <QPainter>

Deur::Deur(int a, int b, unsigned int l): x_coordinaat(a),y_coordinaat(b), lengte(l) {

}

void Deur::open() {
    status = true;
}

void Deur::sluit() {
    status = false;
}

void Deur::teken(QPaintDevice* device) {
    if (!device) return;

    QPainter painter(device);
    painter.setBrush(status ? Qt::green : Qt::red);
    painter.drawRect(x_coordinaat, y_coordinaat, lengte, 20);
}

bool Deur::isDeurOpen() {
    return status;
}
