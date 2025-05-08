#ifndef CODESLOT_H
#define CODESLOT_H

#include "slot.h"

class CodeSlot : public Slot {
private:
    int code;
    bool vergrendeld;
    shared_ptr<QLineEdit> input;
public:
    CodeSlot(string, shared_ptr<QLineEdit>);
    void vergrendel() override;
    bool isVergrendeld() override;
    void ontgrendel() override;
};

#endif // CODESLOT_H
