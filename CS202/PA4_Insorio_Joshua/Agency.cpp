#include <fstream>

#include "Agency.h"
#include "Proj4.h"

using namespace std;

// Operator overloads
std::istream& operator>>(std::istream& is, Agency& agency) 
{
    is >> agency.m_name >> agency.m_zipcode;
    
    for (int i = 0; i < 5; i++) {
        is >> agency[i];
    }
    return is;
}

std::ostream & operator<<(std::ostream & os, Agency & agency) 
{
    os << agency.m_name << " " << agency.m_zipcode << endl;
    
    for (int i = 0; i < 5; i++) {
        os << agency[i] << endl;
    }
    
    return os;
}


Agency::Agency():

m_zipcode(00000)
{
};

// Get methods
const char* Agency::getName() const 
{
    return m_name;
}

const int Agency::getZipcode() const 
{
    return m_zipcode;
}

// Set methods
void Agency::setName(const char* name) 
{
    myStringCopy(m_name, name);
}

void Agency::setzipcode(const int zipcode)
{
    m_zipcode = zipcode;
}

// Operator overload
Car & Agency::operator[](int i) 
{
    return m_inventory[i];
}

// Other methods
void Agency::readAllData() 
{
    ifstream input;
    char filename[256];
    
    cout << "Please enter the file name (including the extension): ";
    cin >> filename;
    input.open(filename);
    input >> *this;

    input.close();
}

void Agency::printAllData() {
    cout << *this;
}

void Agency::printSensorCounts() {
    char sensorType[256];
    int sensorCount = 0, gpsCount = 0, cameraCount = 0, lidarCount = 0, radarCount = 0;
    Car * inventory_ptr = m_inventory;
    Sensor * sensors_ptr;
    
    for (int i = 0; i < 5; i++, inventory_ptr++) 
    {
        
        sensors_ptr = inventory_ptr->getSensors();
        
        for (int j = 0; j < inventory_ptr->getSensorCount(); j++, sensors_ptr++) 
        {   
            
            sensorCount++;
            myStringCopy(sensorType, sensors_ptr->getType());
            if (!myStringCompare(sensorType, "gps")) {
                gpsCount++;
            } else if (!myStringCompare(sensorType, "camera")) {
                cameraCount++;
            } else if (!myStringCompare(sensorType, "lidar")) {
                lidarCount++;
            } else if (!myStringCompare(sensorType, "radar")) {
                radarCount++;
            }
        }
    }
    cout << "Total Sensors: " << sensorCount << "\n" << "GPS: " << gpsCount << "  " << "Camera: " << cameraCount << "  " << "Lidar: " << lidarCount << "  " << "Radar: " << radarCount << endl;
}

void Agency::findMostExpensiveCar() 
{
    Car * mostExpensiveCar;
    Car * inventory_ptr = m_inventory;

    mostExpensiveCar = inventory_ptr;
    
    for (int i = 0; i < 5; i++, inventory_ptr++) 
    {
        if (inventory_ptr->getAvailable() == true) 
        {
            if ((inventory_ptr->getFinalPrice() > mostExpensiveCar->getFinalPrice())) {
                mostExpensiveCar = inventory_ptr;
            }
        }
    }
    
    if (mostExpensiveCar) 
    {
        cout << "Most expensive available car: " << endl;
        cout << *mostExpensiveCar << endl;
        mostExpensiveCar->rent();
    } else {
        cout << "Sorry, there are no available cars." << endl;
    }
}

void Agency::printAvailableCars() {
    Car * inventory_ptr = m_inventory;
    
    cout << "Available cars: " << endl;
    for (int i = 0; i < 5; i++, inventory_ptr++) {
        if (inventory_ptr->getAvailable()) {
            cout << *inventory_ptr << endl;
        }
    }
}