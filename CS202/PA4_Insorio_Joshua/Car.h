#ifndef CAR_H
#define CAR_H

#include <iostream>
#include "Sensor.h"

using namespace std;

//car class and declarations
class Car 
{
    
    friend std::istream& operator>>(std::istream& is, Car& car);
    
    public:
        Car();
        Car(const char *make, const char *model, const int year, const float baseprice, const bool available, Sensor *sensors);
        Car(Car & car);

    
        char * getMake();
        char * getModel();
        int getYear();
        Sensor * getSensors();
        float getBasePrice();
        float getFinalPrice();
        bool getAvailable();
        char * getOwner();
        int getSensorCount();

        
        void setMake(const char * make);
        void setModel(const char * model);
        void setYear(const int year);
        void setBasePrice(const float baseprice);
        void setAvailable(const bool available);
        void setOwner(const char * owner);

        Car& operator+(Sensor & sensor);
        Car& operator+(const char * owner);
        friend ostream & operator<<(ostream & os, const Car & car);
        
        float updatePrice();
        void print();
        float estimateCost(const int days);
        void rent();
        
    private:
        char m_make[256];
        char m_model[256];
        int m_year;
        Sensor m_sensors[3];
        float m_baseprice;
        float m_finalprice;
        bool m_available;
        char m_owner[256];
        int m_sensorCount;
};


#endif


