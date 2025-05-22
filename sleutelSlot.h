#include "ISlot.h"
#include <memory>

#ifndef SLEUTELSLOT_H
#define SLEUTELSLOT_H

class SleutelSlot : public Slot {
private:
    string sleutel;
    bool vergrendeld = true;
public:
    SleutelSlot(string);
    void vergrendel() override;
    bool isVergrendeld() const override;
    void ontgrendel(string) override;
};

#endif // SLEUTELSLOT_H
