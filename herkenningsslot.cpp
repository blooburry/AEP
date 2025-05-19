#include "herkenningsslot.h"

Herkenningsslot::Herkenningsslot(
    shared_ptr<QLineEdit> input,
    shared_ptr<QLineEdit> adminInput,
    unique_ptr<IAfdrukker> d):
    input(input),
    adminInput(adminInput),
    display(std::move(d)) {
}

bool Herkenningsslot::isVergrendeld() const {
    return this->vergrendeld;
}

void Herkenningsslot::ontgrendel() {
    string s = this->input->text().toStdString();
    if(this->kaartenbak.find(s) != kaartenbak.end()) {
        if(this->kaartenbak[s]) this->vergrendeld = false;
    }
}

void Herkenningsslot::vergrendel() {
    this->vergrendeld = true;
    this->input->clear();
}

void Herkenningsslot::toonKaartenbak() const {
    this->display->clearMedium();
    for(const auto& [k, v] : this->kaartenbak) {
        this->display->toonTekst(k + ": " + (v? "toegestaan": "verboden"));
    }
}

void Herkenningsslot::voegAutorisatieToe(bool allow) {
    const string s = this->adminInput->text().toStdString();
    if(s.length() == 0) return;
    this->kaartenbak.insert({s, allow});
}
