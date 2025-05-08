#ifndef SENSOR_H
#define SENSOR_H

#include <utility>

using namespace std;


class QPaintDevice;

class Sensor
{
public:
    Sensor(int,int);
    virtual void teken(QPaintDevice*)=0;
    void activeer();
    void deactiveer();
    bool isGeactiveerd()const;
    std::pair<int,int> coordinaten() const;

    int getX() const;
    int getY() const;
    bool getGeactiveerd() const;

private:
    int x,y;
    bool geactiveerd;
};

#endif // SENSOR_H
