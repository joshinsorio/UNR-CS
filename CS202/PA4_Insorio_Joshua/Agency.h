#ifndef AGENCY_H
#define AGENCY_H

#include "Car.h"


class Agency {
    
    friend std::istream & operator>>(std::istream& is, Agency& agency);
    friend std::ostream & operator<<(std::ostream & os, Agency & agency);

private:
    char m_name[256];
    int m_zipcode;
    Car m_inventory[5];
public:
    Agency();
    
    // Get methods
    const char* getName() const;
    const int getZipcode() const;
    
    // Set methods
    void setName(const char* name);
    void setzipcode(const int zipcode);
    
    // Operator overloads
    Car & operator[](int i);
    
    // Other methods
    void readAllData();
    void printAllData();
    void printSensorCounts();
    void findMostExpensiveCar();
    void printAvailableCars();
    
};


#endif
