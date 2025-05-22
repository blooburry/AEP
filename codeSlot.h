#ifndef CODESLOT_H
#define CODESLOT_H

#include "ISlot.h"
#include "defines.h"

class CodeSlot : public Slot {
private:
    int code;
    bool vergrendeld = true;
public:
    CodeSlot(string);
    void vergrendel() override;
    bool isVergrendeld() const override;
    void ontgrendel(string) override;
};

#endif // CODESLOT_H
