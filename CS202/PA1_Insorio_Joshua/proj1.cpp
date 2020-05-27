//Name: Joshua Insorio 
//Date: 9.5.17
//Proj1.h

#include <iostream>
#include <fstream>

using namespace std;


void myStringCopy(char destination[], const char source[]);
int myStringLength(const char str[]);
int myStringCompare(const char str1[], const char str2[]);

int main()
{
    char firstname[10][9];
    int lengths[10];
    int organizer[10];
    char preswitch[10][9];
    char input1[30], output1[30], output2[30];
    fstream names;

    cout << "What is the name of the input file and your two output files? (Seperate by spaces and include and extenstion)\n";
    cin >> input1 >> output1 >> output2;

    names.open(input1); //Opens input file as decided by the user

    for(int r = 0; r < 10; r++)//Inputting the names from the source file along with outputting into terminal
    {
        names >> firstname[r];
        organizer[r] = r;
    }

   for(int r = 0; r < 10; r++) //Creation of a new array to store in names before sorting, for easier outputting later
    {
        myStringCopy(preswitch[r], firstname[r]);
    }

   for(int r = 0; r < 10; r++) //Printing the names
    {
        cout << r << ' ' << firstname[r];
        cout << endl;
    }
 
    int i = 0;
        cout << "\nSorted-by-Length Data (Original Input Order and Name) \n ===========================\n";

        for(; i < 10; i++)//Counting the lengths of each name and inserting into a separate array for organization and swapping later
        {
            lengths[i] = myStringLength(firstname[i]);
        }

        for(int k = 0;k < 10;k++) //Sorting the names by length along with the stored lengths array and the original places
        {
            for(int i = 0; i < 9; i++)
            {
                if(lengths[i] > lengths[i+1])
                {
                    swap(lengths[i], lengths[i+1]);
                    swap(firstname[i], firstname[i+1]);
                    swap(organizer[i], organizer[i+1]);
                }
            }
        }

        for(int k = 0; k < 10; k++)//Printing the sorted names
        {
            cout << organizer[k] << " " << firstname[k] << "\n";
        }

        ofstream outfile1(output1); 

        for(int r = 0; r < 10; r++)//Writing the unsorted names into an output file as named by the user
        {
            outfile1 << preswitch[r] << endl;
        }
        outfile1 << endl;
        for(int r = 0; r < 10; r++)//Writing the sorted names into an ou  tput file as named by the user
        {
            outfile1 << firstname[r] << endl;
        }
        outfile1.close();

        cout << "\nAlphabetcially Sorted Data (Original Input Order and Name) \n =========================== \n";

        for(int k = 0;k < 10;k++)
        {
            for(int i = 0; i < 9; i++)
            {

                switch(myStringCompare(firstname[i], firstname[i+1]))
                {
                    case 1:
                        swap(firstname[i], firstname[i+1]);
                        swap(organizer[i], organizer[i+1]);
                        break;
                    case 0:
                        break;
                    case -1:
                        break;

                }
            }
        }

        for(int k = 0; k < 10; k++)
        {
            cout << organizer[k] << " " << firstname[k] << "\n";
        }

        ofstream outfile2(output2);

        for(int r = 0; r < 10; r++)//Writing the unsorted names into an output file as named by the user
        {
            outfile2 << preswitch[r] << endl;
        }
        outfile2 << endl;
        for(int r = 0; r < 10; r++)//Writing the sorted names into an output file as named by the user
        {
            outfile2 << firstname[r] << endl;
        }
        outfile2.close();

    names.close(); //Closes the original file of input

    return 0;
}

void myStringCopy(char destination[], const char source[])//Function used to copy a string into another one
{
    char i = 0;
        while(source[i] != '\0')
        {
            destination[i] = source[i];
            i++;
        }
        destination[i] = '\0';
}

int myStringLength(const char str[]) //Function used to count the length of a string by counting each place until reaching a null character
{
    int n = 0, s = 0;
    for(; str[s] != '\0'; s++)
    {
        n++;
    }

    return n;
}

int myStringCompare(const char str1[], const char str2[])//Function used to compare each letter of a string and returning a value based on if statements
{
    int i = 0;
    for(;str1[i] == str2[i]; i++)
    {
        if((str1[i] == '\0') && (str2[i] == '\0'))
        {
            return 0;
        }
    }

    if(str1[i] > str2[i])
    {
        return 1;
    }
    else 
    {
        return -1;
    }
    return 0;
    //return str1[i] > str2[i] ? 1 : -1;

}