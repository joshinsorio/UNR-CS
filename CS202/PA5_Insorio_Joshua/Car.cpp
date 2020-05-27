#include <iostream>
#include <fstream>
#include <string.h>
#include "Vehicle.h"
#include "Car.h"


using namespace std;

    //Ctors - default, parameterized, copy, dtor
Car::Car()
{
	cout << "Car #" << m_vin << ": Default-ctor" << endl;
	m_throttle = 0;
}

Car::Car(char *plates, int vin, float *lla)
{

	strcpy(m_plates, plates);

	for (int i = 0; i < 3; i++, lla++) {
		m_lla[i] = *lla;
	}

	cout << "Car #" << m_vin << ": Parametrized-ctor" << endl;
}

Car::Car(const Car &other)
{

	for (int i = 0; i < 256; i++)
		m_plates[i] = other.m_plates[i];

	strcpy(m_plates, other.m_plates);

	for (int i = 0; i < 3; i++) {
		m_lla[i] = other.m_lla[i];
	}

	setThrottle(other.m_throttle);

	cout << "Car #" << m_vin << ": Copy-ctor" << endl;
}

Car::~Car()
{
	cout << "Car #" << m_vin << ": Dtor" << endl;
}

//Get methods
char *Car::getPlates()
{
	return m_plates;
}

int Car::getThrottle()
{
	return m_throttle;
}

//Set methods
void Car::setPlates(char *plates)
{
	strcpy(m_plates, plates);
}

void Car::setThrottle(int throttle)
{
	m_throttle = throttle;
}

//Methods
void Car::drive(int throttle)
{
	setThrottle(throttle);
}

void Car::move(float *lla)
{
	for (int i = 0; i < 3; i++, lla++) 
	{
		m_lla[i] = *lla;
	}
	cout << "Car #" << m_vin << ": DRIVE to destination, with throttle @ 75" << endl;
	drive(75);
}

//Assignemnt operator=
Car &Car::operator=(const Car &other)
{
	strcpy(m_plates, other.m_plates);
	m_throttle = other.m_throttle;
	//m_vin = other.m_vin;

	for (int i = 0; i < 3; i++) 
	{
		m_lla[i] = other.m_lla[i];
	}

	cout << "Car #" << m_vin << ": Assignment" << endl;
	return *this;
}

ostream &operator<<(std::ostream &output, Car &car)
{
	output << "Car #" << car.m_vin << " Plates: " << car.m_plates << ", Throttle: " << car.m_throttle
		<< " @ [" << car.m_lla[0] << ", " << car.m_lla[1] << ", " << car.m_lla[2] << "]" << endl;
	return output;
}

