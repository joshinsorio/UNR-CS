//Name: Joshua Insorio 
//Date: 9.11.17
//Proj2.h

#include <iostream>
#include <fstream>
using namespace std;

size_t myStringLength(const char * str);
int myStringCompare(const char * str2, const char * str3);
char * myStringCopy(char * destination, const char * source);
char * myStringCat(char * destination, const char * source);
void structinput(struct cars * list);
void structprint(struct cars * list);
void structoutput(struct cars * list);
void structprice(struct cars * list);
void structrent(struct cars * list);
void structchoose(struct cars * list);

struct cars
{
    int year;
    char make[20];
    char model[20];
    float price;
    bool available;
};

int main()
{
    fstream names;

    cars list[6];


    int choice;
    cout << "Options: \n1 - Source file entry\n2 - Print out data\n3 - Export all data into seperate file\n4 - Sort by ascending price\n5 - Estimated rent per day\n6 - Choose car to rent\n7 - Exit program\n";
    cout << "Please enter your option" << endl;
    cin >> choice;

    while(choice == 0 || choice > 8)//Display menu
    {
        cout << "Invalid option, please reselect\n";
        cout << "Options: \n1 - Source file entry\n2 - Print out data\n3 - Export all data into seperate file\n4 - Sort by ascending price\n5 - Estimated rent per day\n - Choose car to rent\n7 - Exit program\n";
        cin >> choice;
    }

    while((choice < 8) && (choice > 0))//Switch statement for the menu
    {

        switch(choice)
            {
                case 1:
                    structinput(list);
                    break;

                case 2: 
                    structprint(list);
                    break;

                case 3:
                    structoutput(list);
                    break;

                case 4:
                    structprice(list);
                    break;

                case 5:
                {
                    structrent(list);
                    break;
                }

                case 6:
                    structchoose(list);
                    break;
                case 7:
                    return 0;

            }
        cout << "Options: \n1 - Source file entry\n2 - Print out data\n3 - Export all data into seperate file\n4 - Sort by ascending price\n5 - Estimated rent per day\n6 - Choose car to rent\n7 - Exit program\n";
        cout << "Please enter your option" << endl;
        cin >> choice;
    }


    return 0;
}


void structinput(struct cars * list)//Inputting the info from source file into structs
{
    char input[30];
    fstream names;
    cout << "What is the name of the input file?(Seperate by spaces and include and extenstion)\n";
    cin >> input;
    names.open(input);
    for(int r = 0; r < 5; r++)
    {
        names >> list[r].year;
        names >> list[r].make;
        names >> list[r].model;
        names >> list[r].price;
        names >> list[r].available;
    }
    names.close();    
}

void structprint(struct cars * list)//Outputting the info into the terminal
{
    for(int r = 0; r < 5; r++)
    {
        cout << " " << list[r].year;
        cout << " " << list[r].make;
        cout << " " << list[r].model;
        cout << ", $" << list[r].price << " per day";
        cout << ", Available: " << boolalpha <<list[r].available << endl;
    }
}

void structoutput(struct cars * list)//Outputting the info into a new file
{
    char output[30];
    cout << "Please enter your output file destination. (Include extension)\n";
    cin >> output;
    ofstream output2(output);

    for(int r = 0; r < 5; r++)
    {
        output2 << " " << list[r].year;
        output2 << " " << list[r].make;
        output2 << " " << list[r].model;
        output2 << ", $" << list[r].price << " per day";
        output2 << ", Available: " << boolalpha << list[r].available << endl;
    }
    output2.close();
}

void structprice(struct cars * list)//Sort the structs price by ascending order
{
    for(int r = 0; r < 4; r++)
        for(int i = 0; i < 4; i++)
        {
            if(list[i].price > list[i+1].price)
            {
                swap(list[i].year, list[i+1].year);
                swap(list[i].make, list[i+1].make);
                swap(list[i].model, list[i+1].model);
                swap(list[i].price, list[i+1].price);
                swap(list[i].available, list[i+1].available);
            }
        }
}

void structrent(struct cars * list)//Display rent of car for # of days
{
    int days, cost;
    cout << "How many days would you like to rent the car for?\n";
    cin >> days;
    for(int r = 0; r < 5; r++)
        for(int i = 0; i < 5; i++)
        {
            if(list[i].price < list[i+1].price)
            {
                swap(list[i].year, list[i+1].year);
                swap(list[i].make, list[i+1].make);
                swap(list[i].model, list[i+1].model);
                swap(list[i].price, list[i+1].price);
                swap(list[i].available, list[i+1].available);
            }
        }
    for(int r = 0; r < 5; r++)//Outputting the info into the terminal
    {
        if(list[r].available == 1)
        {
            cout << " " << list[r].year;
            cout << " " << list[r].make;
            cout << " " << list[r].model;
            cout << ", Estimated Cost: $" << days * list[r].price << endl;
        }
    }
}

void structchoose(struct cars * list)//Prompts user to choose an available car and to book it
{
    int car_choice, days;
    cout << "Which car would you like to rent?(Please input the car number, starting from the top down)\n";
    cin >> car_choice;

    while(list[car_choice - 1].available == 0)
    {
    cout << "Sorry the car you selected is already rented, please select again.\n";
    cout << "Which car would you like to rent?(Please input the car number, starting from the top down)\n";
    cin >> car_choice;
    }
    while(car_choice >= 6)
    {
    cout << "Sorry there is no such car.\n";
    cout << "Which car would you like to rent?(Please input the car number, starting from the top down)\n";
    cin >> car_choice;
    }

    cout << "How many days would you like to rent this car?\n";
    cin >> days;

    list[car_choice-1].available = 0;
    cout << "Congratulations, your booking has been confirmed, your total is: $" << days * list[car_choice-1].price << endl;
}

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
