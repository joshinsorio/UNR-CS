#include <iostream>
#include <fstream>
#include "Vehicle.h"
#include "Car.h"

using namespace std;


    //Ctors - default, parameterized, copy, dtor
    Car::Car() : m_throttle(0)
    {
        std::cout << "Car" << ": Default-ctor" << std::endl;
    };
    
    Car::Car(float * lla) : m_throttle(0)
    {
        Vehicle::SetLLA(lla);
        std::cout << "Car" << ": Parametrized-ctor" << std::endl;
    };
    Car::Car(const Car &other)
    {
        
        for (int i = 0; i < 3; i++)
            m_throttle = other.m_throttle;

        cout << "Car" << ": Copy-ctor" << endl;
    };
    Car::~Car()
    {
        std::cout << "Car" << ": Dtor" << std::endl;
    };

    Car& Car::operator=(const Car& other)
    {
      if (this != &other)
      {  
        for(int i = 0; i < 3; i++)
        {
            m_lla[i] = other.m_lla[i];
        }
        std::cout << "Car " << ": Assignment" << std::endl;
      }
      return *this;
    };

    //set methods
    void Car::setThrottle(int throttle)
    {
        m_throttle = throttle;
    };

    //get methods
    int Car::getThrottle()
    {
        return m_throttle;
    };

    //drive methods
    void Car::drive(int throttle)
    {
        setThrottle(throttle);
    };

    //move method
    void Car::Move(float *data)
    {
        Vehicle::SetLLA(data);
        cout << "Car: DRIVE to destination, with throttle @ 75" << endl;
	    drive(75);
    };

    //operator overload
    std::ostream &operator<<(std::ostream& os, Car &other)
    {
        other.serialize(os);
        //os << "Car" << "@[" << other.m_lla[0] << "," << other.m_lla[1] << "," << other.m_lla[2] << "]" << endl;
        return os;
    };

    //Serialize method
    void Car::serialize(std::ostream& os)
    {
        os << "Car @[" << m_lla[0] << "," << m_lla[1] << "," << m_lla[2] << "]" << endl;
    };
