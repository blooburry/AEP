#include "slot.h"
#include <memory>

#ifndef SLEUTELSLOT_H
#define SLEUTELSLOT_H

class SleutelSlot : public Slot {
private:
    string sleutel;
    bool vergrendeld;
    shared_ptr<QLineEdit> input;
public:
    SleutelSlot(string, shared_ptr<QLineEdit>);
    void vergrendel() override;
    bool isVergrendeld() const override;
    void ontgrendel() override;
};

#endif // SLEUTELSLOT_H
