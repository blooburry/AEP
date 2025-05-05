#include "sleutelslot.h"

SleutelSlot::SleutelSlot(string s): sleutel(s), vergrendeld(true) {}

void SleutelSlot::ontgrendel(string s) {
    if(s == this->sleutel) {
        this->vergrendeld = false;
    }
}

bool SleutelSlot::isVergrendeld() {
    return this->vergrendeld;
}

void SleutelSlot::vergrendel() {
    this->vergrendeld = true;
}
