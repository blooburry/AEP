#include <string>

using namespace std;

#ifndef SLOT_H
#define SLOT_H

class Slot {
public:
    virtual void ontgrendel(string) = 0;
    virtual void vergrendel() = 0;
    virtual bool isVergrendeld() = 0;
};

#endif // SLOT_H
