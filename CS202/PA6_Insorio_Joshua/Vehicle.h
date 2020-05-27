#ifndef VEHICLE_H
#define VEHICLE_H



//Vehicle Class declaration
class Vehicle
{
private:
    virtual void serialize(std::ostream& os);
protected:
    float m_lla[3];

public:
	//Ctors - default, parameterized, copy, dtor
	Vehicle();
	Vehicle(float *lla);
	Vehicle(const Vehicle &other);
	virtual ~Vehicle();

	//Get methods
    float * getLLA();

	//Set methods
    void SetLLA(float * lla);
    

	//Methods
	virtual void Move(float *data) = 0;

	//Operator overload
	//Assignment operator
	Vehicle &operator=(const Vehicle &other);

	//Insertion operator
	friend std::ostream &operator<<(std::ostream &os, Vehicle &other);


};


#endif