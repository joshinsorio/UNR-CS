#include <iostream>
#include <fstream>
#include "Vehicle.h"

using namespace std;


    //Ctors - default, parameterized, copy, dtor
    Vehicle::Vehicle()
    {
        std::cout << "Vehicle" << ": Default-ctor" << std::endl;
    };
    
    Vehicle::Vehicle(float *lla)
    {
        Vehicle::SetLLA(lla);
        std::cout << "Vehicle" << ": Parametrized-ctor" << std::endl;
    };
    Vehicle::Vehicle(const Vehicle &other)
    {
        
        for (int i = 0; i < 3; i++)
            m_lla[i] = other.m_lla[i];

        //Prints out information and increments s_idgen
        cout << "Vehicle" << ": Copy-ctor" << endl;
    };
    Vehicle::~Vehicle()
    {
        std::cout << "Vehicle" << ": Dtor" << std::endl;
    };

    Vehicle& Vehicle::operator=(const Vehicle& other)
    {
      if (this != &other)
      {  
        for(int i = 0; i < 3; i++)
        {
            m_lla[i] = other.m_lla[i];
        }
        //setVin(other.);
        std::cout << "Vehicle " << ": Assignment" << std::endl;
      }
      return *this;
    };

    //set methods
    void Vehicle::SetLLA(float *lla)
    {
        for(int i = 0; i < 3; i++, lla++)
        {
            m_lla[i] = *lla;
        }
    };

    //get methods
    float * Vehicle::getLLA()
    {
        return m_lla;
    };

    //move methods
    void Vehicle::Move(float *data)
    {
        for(int i = 0; i < 3; i++, data++)
        {
            *data = m_lla[i];
        }
        //cout << "Vehicle #" << getVin() << ": CANNOT MOVE - I DON'T KNOW HOW" << endl;
    };

    //operator overload
    std::ostream &operator<<(std::ostream& os, Vehicle &other)
    {
        other.serialize(os);
        //os << "Vehicle" << "@[" << other.m_lla[0] << "," << other.m_lla[1] << "," << other.m_lla[2] << "]" << endl;
        return os;
    };

    //Serialize method
    void Vehicle::serialize(std::ostream& os)
    {
        os << "Vehicle @[" << m_lla[0] << "," << m_lla[1] << "," << m_lla[2] << "]" << endl;
    };
