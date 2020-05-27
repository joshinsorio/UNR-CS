#ifndef CAR_H
#define CAR_H


//Vehicle Class declaration
class Car: public Vehicle
{
private:
	char m_plates[256];
	int m_throttle;

public:
	//Ctors - default, parameterized, copy, dtor
	Car();
	Car(char *plates, int vin, float *lla);
	Car(const Car &source);
	~Car();

	//Get methods
	char *getPlates();
	int getThrottle();

	//Set methods
	void setPlates(char *plates);
	void setThrottle(int throttle);

	//Methods
	void drive(int throttle);
	void move(float *lla);

	//Operator overload
	//Assignment operator
	Car &operator=(const Car &other);

	//Insertion operator
	friend std::ostream &operator<<(std::ostream &output, Car &car);


};


#endif