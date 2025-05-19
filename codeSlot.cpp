#include "codeSlot.h"
#include <stdexcept>

CodeSlot::CodeSlot(string s, shared_ptr<QLineEdit> i) : code(stoi(s)), vergrendeld(true), input(i) {}

bool CodeSlot::isVergrendeld() const {
    return this->vergrendeld;
}

void CodeSlot::ontgrendel() {
    string a = this->input->text().toStdString();

    try {
        int i = std::stoi(a);
        if(i == this->code) {
            this->vergrendeld = false;
        }
    } catch (const std::invalid_argument& e) {

    }
}

void CodeSlot::vergrendel() {
    this->vergrendeld = true;
    this->input->clear();
}
