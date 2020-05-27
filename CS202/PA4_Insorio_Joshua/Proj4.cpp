#include <iostream>
#include <fstream>

#include "Proj4.h"
#include "Sensor.h"
#include "Car.h"
#include "Agency.h"

using namespace std;

int main () 
{
    
    Agency agency;
    
    ifstream input;
    bool exit = false;
    int choice = 0;

    //Menu display
    cout << "Options: \n1 - Read all data from file\n2 - Print out data\n3 - Show total sensor counts\n4 - Find most expensive car\n5 - Exit\n";
    cin >> choice;
    
    //Invalid option display
    while(choice == 0 || choice > 6)
    {
        cout << "Invalid option, please reselect\n";
        cout << "Options: \n1 - Read all data from file\n2 - Print out data\n3 - Show total sensor counts\n4 - Find most expensive car\n5 - Exit\n";
        cin >> choice;
    }

    //Menu navigation
    while((choice < 6) && (choice > 0))
    {
        switch(choice){
            case 1:
                agency.readAllData();
                break;
            case 2: 
                agency.printAllData();
                break;
            case 3: 
                agency.printSensorCounts();
                break;
            case 4: 
                agency.findMostExpensiveCar();
                break;
            case 5: 
                return 0;
                break;

            }

        cout << "Options: \n1 - Read all data from file\n2 - Print out data\n3 - Show total sensor counts\n4 - Find most expensive car\n5 - Exit\n";
        cout << "Please enter your option" << endl;
        cin >> choice;
    }

    return 0;
    
}




//String functions
size_t myStringLength(const char * str) {
    size_t i = 0;
    
    while (*str++) {
        i++;
    };
    
    return i;
}

int myStringCompare(const char * str1, const char * str2) {
    while (*str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
    }
    
    return *str1 - *str2;
}

char *myStringCopy(char * destination, const char * source) {
    while ((*destination++ = *source++))
        ;
    
    return destination;
}

char *myStringCat(char * destination, const char * source) {
    while (*destination) {
        destination++;
    }
    while ((*destination++ = *source++));
    return destination;
}


