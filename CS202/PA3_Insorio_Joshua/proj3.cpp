//Name: Joshua Insorio 
//Date: 9.16.17
//Proj3.h

#include <iostream>
#include <fstream>
using namespace std;

size_t myStringLength(const char * str);
int myStringCompare(const char * str2, const char * str3);
char * myStringCopy(char * destination, const char * source);
char * myStringCat(char * destination, const char * source);
void input(struct RentalAgency * Agencyptr);
void infoprint(RentalAgency * Agencyptr);
void rentalcost(RentalAgency * Agencyptr);
void expensivecar(RentalAgency * Agencyptr);
void output(RentalAgency * Agencyptr);

class RentalCar //RentalCar Class
{
    private:
        int m_year;
        char m_make[256];
        char m_model[256];
        float m_price;
        bool m_available;

    public: //Functions to interact with the private data
        RentalCar()
        {
            m_available = false;
        };

        void setYear(int year)
        {
            m_year = year;
        };
        void setMake(char make[256])
        {
            for(int i = 0; make[i] != '\0'; i++)
            { 
                myStringCopy(m_make, make);
            }
        };
        void setModel(char model[256])
        {
            for(int i = 0; model[i] != '\0'; i++)
            {
                myStringCopy(m_model, model);
            }
        };
        void setPrice(float price)
        {
            m_price = price;
        };
        void setAvailable(bool available)
        {
            m_available = available;
        };

        int getYear()
        {
            return m_year;
        };
        char * getMake()
        {
            return m_make;
        };
        char * getModel()
        {
            return m_model;
        };
        float getPrice()
        {
            return m_price;
        };
        bool getAvailable()
        {
            return m_available;
        };

        void Input(int year, char make[256], char model[256], float price, bool available)
        {
            m_year = year;
            for(int i = 0; make[i] != '\0'; i++)
            {
                m_make[i] = make[i];
            }
            for(int i = 0; model[i] != '\0'; i++)
            {
                m_model[i] = model[i];
            }
            m_price = price;
            m_available = available;
        };

        float estimatecost(int days)
        {
            int total = 0;
            total = days * m_price;
            return total;
        };

        void print()
        {
            cout << m_year << " " << m_make << " " << m_model << ", $" << m_price << boolalpha << ", Available: " << m_available << endl;
        };

};

struct RentalAgency //Struct
{
    char name[30];
    int zipcode[5];
    RentalCar inventory[5];
};


int main()
{
    RentalAgency list[3];
    RentalAgency *Agencyptr = list;
    

    int choice;
    cout << "Options: \n1 - Source file entry\n2 - Print out data\n3 - Estimate car rental\n4 - Find most expensive car\n5 - Export all available cars\n6 - Exit\n";
    cout << "Please enter your option" << endl;
    cin >> choice;

    while(choice == 0 || choice > 7)//Display menu
    {
        cout << "Invalid option, please reselect\n";
        cout << "Options: \n1 - Source file entry\n2 - Print out data\n3 - Estimate car rental\n4 - Find most expensive car\n5 - Export all available cars\n6 - Exit\n";
        cin >> choice;
    }

    while((choice < 7) && (choice > 0))//Switch statement for the menu
    {

        switch(choice)
            {
                case 1:
                    input(list);
                    break;

                case 2: 
                    infoprint(Agencyptr);
                    break;

                case 3:
                    rentalcost(Agencyptr);
                    break;

                case 4:
                    expensivecar(Agencyptr);
                    break;

                case 5:
                {
                    output(Agencyptr);
                    break;
                }
                case 6:
                    return 0;

            }
        cout << "Options: \n1 - Source file entry\n2 - Print out data\n3 - Estimate car rental\n4 - Find most expensive car\n5 - Export all available cars\n6 - Exit\n";
        cout << "Please enter your option" << endl;
        cin >> choice;
    }


    return 0;
}

void input(struct RentalAgency *Agencyptr) //Function to input all agency information
{
	int year, zip, result, divider;
	char make[256], model[256], input[30];
	float price;
	bool available;
	
	int *zipPtr;
	RentalCar *inventoryptr;
	
	cout << "Please enter input file name with extension: " << endl;
	cin >> input;
	
	ifstream infile;
	infile.open(input);
	
	for(int i = 0; i < 3; Agencyptr++, i++)
	{ 
		infile >> Agencyptr->name;
		infile >> zip;
		divider = 10000;
		
		inventoryptr = Agencyptr->inventory;
		zipPtr = Agencyptr->zipcode;

		for(int j = 0; j < 5; zipPtr++, j++)
		{
			result = zip;
			result /= divider;
			zip -= result*divider;
			divider /= 10;
			*zipPtr = result;
		}

		for(int k = 0; k < 5; inventoryptr++, k++)
		{
			infile >> year;
            infile >> make;
            infile >> model;
            infile >> price;
            infile >> available;
			inventoryptr->setYear(year);
			inventoryptr->setMake(make);
			inventoryptr->setModel(model);
			inventoryptr->setPrice(price);
			inventoryptr->setAvailable(available);
		}
	}
		
	infile.close();
}

void infoprint(RentalAgency * Agencyptr)// Function to print all the Agency information into the terminal
{
    int *zipptr;
    RentalCar * inventoryptr;

    for(int i = 0; i < 3; i++, Agencyptr++)
    {
        zipptr = Agencyptr -> zipcode;
        inventoryptr = Agencyptr -> inventory;

        cout << Agencyptr -> name << " ";
        for(int i = 0; i < 5; i++, zipptr++)
        {
            cout << *zipptr;
        }
        cout << endl;
        for(int i = 0; i < 5; i++, inventoryptr++)
        {
            inventoryptr -> print();
        }
        cout << endl;

    }
}

void rentalcost(RentalAgency * Agencyptr)//Function to estimate and print the cost of a car of the users choice
{
    RentalCar * inventoryptr;
    inventoryptr = Agencyptr -> inventory;

    int option1, option2, days;
	cout << "Which agency would you like to select (1-3)?" << endl;
	cin >> option1;
	cout << "Which car would you like to select (1-5)?" << endl;
	cin >> option2;
	cout << "How many days would you like to rent?" << endl;
	cin >> days;

    for(int i = 0; i < option1; Agencyptr++, i++)
	{
		inventoryptr = Agencyptr->inventory;
		
		for(int j = 0; j < option2 - 1; inventoryptr++, j++)
		{
			
		}
		
	}
    inventoryptr->print();
    cout << "\nEstimatd cost for agency #"<< option1 << " car #" << option2 << " is $" << inventoryptr->estimatecost(days) << "\n" << endl;

}

void expensivecar(RentalAgency * Agencyptr)//Function to find the most expensive car from all the agencies
{
	RentalCar *inventoryptr;
	RentalCar *tempptr;
	inventoryptr = Agencyptr->inventory;
	tempptr = inventoryptr;
	
	float highestPrice = inventoryptr->getPrice();
	
	for(int i = 0; i < 3; Agencyptr++, i++)
	{
		inventoryptr = Agencyptr->inventory;
		
		for(int j = 0; j < 5; inventoryptr++, j++)
		{
			if(inventoryptr -> getPrice() > highestPrice)
			{
				highestPrice = inventoryptr->getPrice();
				tempptr = inventoryptr;
			}
		}
	}
	
    cout << "The most expensive car is ";
	tempptr->print();
}

void output(RentalAgency *Agencyptr) //Function to output all the available cars into a separate file
{	
	char output[30];
	
	RentalCar *inventoryptr;
	
	cout << "Please enter output file name: " << endl;
	cin >> output;
	
	ofstream outfile;
	outfile.open(output);
	
	for(int i = 0; i < 3; Agencyptr++, i++)
	{ 
		inventoryptr = Agencyptr -> inventory;
		
		for(int k = 0; k < 5; inventoryptr++, k++)
		{
			if(inventoryptr -> getAvailable() == 1)
			{
				outfile << inventoryptr -> getYear() << " " << inventoryptr -> getMake() << " " << inventoryptr -> getModel() << " " << inventoryptr -> getPrice() << " " << inventoryptr -> getAvailable() << endl;
			}
		}
	}
	outfile.close();
}






//string functions 

size_t myStringLength(const char * str)
{
    int n = 0, s = 0;
    for(; str[s] != '\0'; s++)
    {
        n++;
    }

    return n;
}

int myStringCompare(const char * str1, const char * str2)
{
    int i = 0;
    for(;*str1 == *str2; str1++, str2++)
    {
        if((*str1 == '\0') && (*str2 == '\0'))
        {
            return 0;
        }
    }
    return *str1 > *str2 ? 1 : -1;
}
char * myStringCopy(char * destination, const char * source)
{
    while(*source != '\0')
    {
        *destination = *source;
        source++;
        destination++;
    }
    *destination = '\0';
    return destination;
}

char * myStringCat(char * destination, const char * source)
{
    while(*destination !='\0')
    {
        destination++;
    }
    while(*source != '\0')
    {
        *destination = *source;
        source++;
        destination++;
    }
    *destination = '\0';
    return destination;
}
