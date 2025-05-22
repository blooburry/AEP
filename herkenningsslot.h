#ifndef HERKENNINGSSLOT_H
#define HERKENNINGSSLOT_H

#include "ISlot.h"
#include "defines.h"
#include "IAfdrukker.h"
#include <map>
#include <memory>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextBrowser>

class Herkenningsslot: public Slot {
private:
    std::map<string, bool> kaartenbak;
    bool vergrendeld = true;
    unique_ptr<IAfdrukker> display;
public:
    Herkenningsslot(unique_ptr<IAfdrukker>);
    void vergrendel() override;
    bool isVergrendeld() const override;
    void ontgrendel(string) override;
    void toonKaartenbak() const;
    void voegAutorisatieToe(string, bool);
};

#endif // HERKENNINGSSLOT_H
