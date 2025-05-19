#include "sleutelslot.h"

SleutelSlot::SleutelSlot(string s, shared_ptr<QLineEdit> i): sleutel(s), vergrendeld(true), input(i) {}

void SleutelSlot::ontgrendel() {
    string s = this->input->text().toStdString();

    if(s == this->sleutel) {
        this->vergrendeld = false;
    }
}

bool SleutelSlot::isVergrendeld() const {
    return this->vergrendeld;
}

void SleutelSlot::vergrendel() {
    this->vergrendeld = true;
    this->input->clear();
}
