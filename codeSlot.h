#ifndef CODESLOT_H
#define CODESLOT_H

#include "slot.h"

class CodeSlot : public Slot {
private:
    int code;
    bool vergrendeld;
public:
    CodeSlot(string);
    void vergrendel() override;
    bool isVergrendeld() override;
    void ontgrendel(string) override;
};

#endif // CODESLOT_H
