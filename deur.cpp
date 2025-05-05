#include "deur.h"

#include <QPaintDevice>
#include <QPainter>

Deur::Deur(int a, int b, unsigned int l, shared_ptr<Slot> s): x_coordinaat(a),y_coordinaat(b), lengte(l), status(false), slot(s) {

}

void Deur::open(string s) {
    this->slot->ontgrendel(s);
    if(!this->slot->isVergrendeld()) {
        status = true;
    }
}

void Deur::sluit() {
    status = false;
    this->slot->vergrendel();
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
