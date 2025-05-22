#include "codeSlot.h"
#include <stdexcept>

CodeSlot::CodeSlot(string s) : code(stoi(s)), vergrendeld(true) {}

bool CodeSlot::isVergrendeld() const {
    return this->vergrendeld;
}

void CodeSlot::ontgrendel(string s) {
    try {
        int i = std::stoi(s);
        if(i == this->code) {
            this->vergrendeld = false;
        }
    } catch (const std::invalid_argument& e) {

    }
}

void CodeSlot::vergrendel() {
    this->vergrendeld = true;
}
