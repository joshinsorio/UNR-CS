#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle
{
    private:
        int m_throttle;
        virtual void serialize(std::ostream &os);
    public:
        Car();
        Car(float *data);
        Car(const Car &other);
        virtual ~Car();
        Car &operator=(const Car &other);

        void setThrottle(int throttle);
        int getThrottle();
        void drive(int throttle);
        virtual void Move(float *data);
        friend std::ostream &operator<<(std::ostream &os, Car &other);

};



#endif