#include "drukbox.h"

Drukbox::Drukbox(shared_ptr<QTextBrowser> d): display(d) {}

void Drukbox::toonTekst(string s) const {
    const QString qs = QString::fromStdString(s);
    this->display->append(qs);
}

void Drukbox::clearMedium() {
    this->display->clear();
}
