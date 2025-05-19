#ifndef HERKENNINGSSLOT_H
#define HERKENNINGSSLOT_H

#include "slot.h"
#include "defines.h"
#include "IAfdrukker.h"
#include <map>
#include <memory>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextBrowser>

class Herkenningsslot: public Slot {
private:
    std::map<string, bool> kaartenbak;
    bool vergrendeld = DICHT;
    shared_ptr<QLineEdit> input;
    shared_ptr<QLineEdit> adminInput;
    unique_ptr<IAfdrukker> display;
public:
    Herkenningsslot(shared_ptr<QLineEdit>, shared_ptr<QLineEdit>, unique_ptr<IAfdrukker>);
    void vergrendel() override;
    bool isVergrendeld() const override;
    void ontgrendel() override;
    void toonKaartenbak() const;
    void voegAutorisatieToe(bool);
};

#endif // HERKENNINGSSLOT_H
