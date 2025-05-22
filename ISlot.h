#include <QtWidgets/QLineEdit>

using namespace std;

#ifndef ISLOT_H
#define ISLOT_H

class Slot {   
public:
    virtual void ontgrendel(string) = 0;
    virtual void vergrendel() = 0;
    virtual bool isVergrendeld() const = 0;
};

#endif // ISLOT_H
