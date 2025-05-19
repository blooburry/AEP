#ifndef DRUKBOX_H
#define DRUKBOX_H

#include "IAfdrukker.h"
#include "QtWidgets/QTextBrowser"
#include <memory>

class Drukbox : public IAfdrukker {
private:
    shared_ptr<QTextBrowser> display;
public:
    Drukbox(shared_ptr<QTextBrowser>);
    void toonTekst(string) const override;
    void clearMedium() override;
};

#endif // DRUKBOX_H
