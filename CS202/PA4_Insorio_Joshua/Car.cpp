#include <iostream>

#include "Car.h"
#include "Sensor.h"
#include "Proj4.h"

using namespace std;

Car::Car() 
{
    setMake("\0");
    setModel("\0");
    setYear(0);
    setBasePrice(0);
    setAvailable(false);
    setOwner("\0");
    
    updatePrice();
    
    m_sensorCount = 0;
    
};

Car::Car(const char *make, const char *model, const int year, const float baseprice, const bool available, Sensor *sensors) 
{
    Sensor * sensor_arr = m_sensors;
    setMake(make);
    setModel(model);
    setYear(year);
    setBasePrice(baseprice);
    setAvailable(available);
    setOwner("\0");
    
    for (int i = 0; i < 3; i++) {
        *sensor_arr++ = Sensor(*sensors++);
        m_sensorCount++;
    }
    
    updatePrice();
    
};

Car::Car(Car & car) 
{
    Sensor * sensors_in = car.getSensors();
    Sensor * sensors_out = m_sensors;
    
    setMake(car.getMake());
    setModel(car.getModel());
    setYear(car.getYear());
    setBasePrice(car.getBasePrice());
    setAvailable(car.getAvailable());
    setOwner(car.getOwner());
    
    for (int i = 0; i < 3; i++) {
        *sensors_out++ = Sensor(*sensors_in++);
    }
    
    updatePrice();
    
    m_sensorCount = car.m_sensorCount;
    
};
//Get methods
char * Car::getMake() 
{ 
    return m_make; 
};

char * Car::getModel() 
{ 
    return m_model; 
};

int Car::getYear() 
{ 
    return m_year; 
};

Sensor * Car::getSensors() 
{
    return m_sensors;
};

float Car::getBasePrice() 
{
    return m_baseprice; 
};

float Car::getFinalPrice() 
{ 
    return m_finalprice; 
};

bool Car::getAvailable() 
{ 
    return m_available; 
};

char * Car::getOwner() 
{ 
    return m_owner; 
};

int Car::getSensorCount() 
{ 
    return m_sensorCount; 
};

//Set methods
void Car::setMake(const char * make) 
{ 
    myStringCopy(m_make, make); 
};

void Car::setModel(const char * model) 
{
    myStringCopy(m_model, model); 
};

void Car::setYear(const int year) 
{ 
    m_year = year; 
};

void Car::setBasePrice(const float baseprice) 
{
    m_baseprice = baseprice; 
};

void Car::setAvailable(const bool available) 
{
    m_available = available; 
};

void Car::setOwner(const char * owner) 
{ 
    myStringCopy(m_owner, owner); 
};

//Operator overloads
Car& Car::operator+(Sensor & sensor) 
{
    Sensor * sensors_ptr = m_sensors;

    for (int i = 0; i < 3; i++, sensors_ptr++) 
    {
        if (!myStringCompare(sensors_ptr->getType(), "none")) 
        {
            sensors_ptr->setType(sensor.getType());
            m_sensorCount++;
            updatePrice();
            break;
        };
    }
    return *this;
};

Car& Car::operator+(const char * owner) 
{
    setOwner(owner);
    setAvailable(false);
    return *this;
};

ostream & operator<<(ostream & os, const Car & car) 
{
    os << " Make: " << car.m_make << ", Model: " << car.m_model << ", Year: " << car.m_year << ", Baseprice: $" << car.m_baseprice << ", Finalprice: $" << car.m_finalprice << ", Available: " << boolalpha << car.m_available << ", Owner: " << car.m_owner ;
    return os;
};

//other methods
 float Car::updatePrice() 
 {
    float price = m_baseprice;
    Sensor * sensors_ptr = m_sensors;
    
    for (int i = 0; i < 3; i++, sensors_ptr++) 
    {
        price += sensors_ptr->getExtraCost();
    }
    
    return m_finalprice = price;
};

void Car::print() 
{
    cout << *this << endl;
};

float Car::estimateCost(const int days) 
{
    return getFinalPrice() * days;
};

void Car::rent() 
{
    char selection;
    
    cout << "Would you like to rent this car?\n Y/N" << endl;
    cin >> selection;
    
    
    if (selection == 'Y') 
    {
        char name[256];
    
        cout << "Please enter your first name: ";
        cin >> name;
        *this + name;

    }
}


std::istream& operator>>(std::istream& is, Car& car) {
    char c;
    char sensor_str[256];
    char * ss_start = sensor_str, * ss_ptr = ss_start;
    Sensor sensor;
    
    is >> car.m_year >> car.m_make >> car.m_model >> car.m_baseprice;
    
    is.get();
    is.get();
    
    while (is >> noskipws >> c) 
    {
        
        if (c != ' ' && c != '}') 
        {
            *ss_ptr++ = c;
        } 
        else 
        {
            *ss_ptr++ = '\0';
            
            if (myStringLength(sensor_str)) 
            {
                sensor.setType(sensor_str);
                car + sensor;
            }
            *ss_start = '\0';
            ss_ptr = ss_start;
        
            if (c == '}') 
            {
                break;
            }
        }
    }
    
    is >> skipws >> car.m_available;
    
    
    if (!car.m_available) 
    {
        is >> car.m_owner;
    }
   
    car.updatePrice();
    
    return is;
};

