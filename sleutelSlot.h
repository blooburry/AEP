#include "slot.h"
#include <memory>

#ifndef SLEUTELSLOT_H
#define SLEUTELSLOT_H

class SleutelSlot : public Slot {
private:
    string sleutel;
    bool vergrendeld;
public:
    SleutelSlot(string);
    void vergrendel() override;
    bool isVergrendeld() override;
    void ontgrendel(string) override;
};

#endif // SLEUTELSLOT_H
