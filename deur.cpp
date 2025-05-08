#include "deur.h"
#include "defines.h"

#include <QPaintDevice>
#include <QPainter>

Deur::Deur(int a, int b, unsigned int l): x_coordinaat(a),y_coordinaat(b), status(false), lengte(l)  {

}

void Deur::voegSlotToe(shared_ptr<Slot> s) {
    sloten.push_back(s);
}

void Deur::open() {
    if(getStatus() == OPEN) return;

    for(shared_ptr<Slot> slot : getSloten()) {
        if(slot->isVergrendeld()) return;
    }
    setStatus(OPEN);
}

void Deur::sluit() {
    if(this->status == DICHT) return;

    for(shared_ptr<Slot> s : this->sloten) {
        s->vergrendel();
    }
    this->status = DICHT;
}

void Deur::teken(QPaintDevice* device) {
    if (!device) return;

    QPainter painter(device);
    painter.setBrush(status ? Qt::green : Qt::red);
    painter.drawRect(x_coordinaat, y_coordinaat, lengte, 20);
}

bool Deur::isDeurOpen() const {
    return status;
}

int Deur::getX() const {
    return x_coordinaat;
}
int Deur::getY() const {
    return y_coordinaat;
}
int Deur::getLen() const {
    return lengte;
}
bool Deur::getStatus() const { return status; }

vector<shared_ptr<Slot>> Deur::getSloten() const {
    return sloten;
}

void Deur::setStatus(bool b) {
    status = b;
}
