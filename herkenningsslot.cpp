#include "herkenningsslot.h"

Herkenningsslot::Herkenningsslot(
    unique_ptr<IAfdrukker> d):
    display(std::move(d)) {
}

bool Herkenningsslot::isVergrendeld() const {
    return this->vergrendeld;
}

void Herkenningsslot::ontgrendel(string input) {
    if(this->kaartenbak.find(input) != kaartenbak.end()) {
        if(this->kaartenbak[input]) this->vergrendeld = false;
        qInfo() << input << "is toegelaten";
    }
}

void Herkenningsslot::vergrendel() {
    this->vergrendeld = true;
}

void Herkenningsslot::toonKaartenbak() const {
    this->display->clearMedium();
    for(const auto& [k, v] : this->kaartenbak) {
        this->display->toonTekst(k + ": " + (v? "toegestaan": "verboden"));
    }
}

void Herkenningsslot::voegAutorisatieToe(string input, bool allow) {
    if(input.length() == 0) return;
    this->kaartenbak.insert({input, allow});
}
