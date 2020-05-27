#include <iostream>
#include <fstream>
#include "Vehicle.h"

using namespace std;

    int Vehicle::s_idgen = 0;

    //Ctors - default, parameterized, copy, dtor
    Vehicle::Vehicle() : m_vin(s_idgen)
    {
        std::cout << "Vehicle #" << m_vin << ": Default-ctor" << std::endl;
        s_idgen++;
    };
    
    Vehicle::Vehicle(int vin, const float * lla) : m_vin(s_idgen)
    {
        std::cout << "Vehicle #" << m_vin << ": Parametrized-ctor" << std::endl;
        s_idgen++;
    }
    Vehicle::Vehicle(const Vehicle &other) : m_vin(s_idgen)
    {
        
        for (int i = 0; i < 3; i++)
            m_lla[i] = other.m_lla[i];

        //Prints out information and increments s_idgen
        cout << "Vehicle #" << m_vin << ": Copy-ctor" << endl;
        s_idgen++;
    }
    Vehicle::~Vehicle()
    {
        std::cout << "Vehicle #" << m_vin << ": Dtor" << std::endl;
        s_idgen--;
    };

    Vehicle& Vehicle::operator=(const Vehicle& other)
    {
      if (this != &other)
      {  
        for(int i = 0; i < 3; i++)
        {
            m_lla[i] = other.m_lla[i];
        }
        //setVin(other.m_vin);
        s_idgen = other.s_idgen;
        std::cout << "Vehicle #" << m_vin << ": Assignment" << std::endl;
      }
      return *this;
    };

    //set methods
    void Vehicle::setLla(float *lla)
    {
        for(int i = 0; i < 3; i++, lla++)
        {
            m_lla[i] = *lla;
        }
    };

    //get methods
    int  Vehicle::getVin()
    {
        return m_vin;
    };
    float * Vehicle::getLla()
    {
        return m_lla;
    };

    int Vehicle::getIdgen()
    {
        return s_idgen;
    };

    //move methods
    void Vehicle::move(float *data)
    {
        for(int i = 0; i < 3; i++, data++)
        {
            *data = m_lla[i];
        }
        cout << "Vehicle #" << getVin() << ": CANNOT MOVE - I DON'T KNOW HOW" << endl;
    };

    //operator overload
    std::ostream& operator<<(std::ostream& os, const Vehicle& other)
    {
        os << "Vehicle #" << other.m_vin << "@[" << other.m_lla[0] << "," << other.m_lla[1] << "," << other.m_lla[2] << "]" << endl;
        return os;
    };
