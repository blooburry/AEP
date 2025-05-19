#ifndef CODESLOT_H
#define CODESLOT_H

#include "slot.h"
#include "defines.h"

class CodeSlot : public Slot {
private:
    int code;
    bool vergrendeld = DICHT;
    shared_ptr<QLineEdit> input;
public:
    CodeSlot(string, shared_ptr<QLineEdit>);
    void vergrendel() override;
    bool isVergrendeld() const override;
    void ontgrendel() override;
};

#endif // CODESLOT_H
