#include <iostream>
#include "link.cpp"
using namespace std;

int main()
{
    
    int choice;
    list<int> sl;
    
    //Looping the menu until the user decides to exit
    while(true)
    {
        cout<<endl<<"---------------------------------"<<endl;
        cout<<endl<<"Operations on singly linked list"<<endl;
        cout<<endl<<"---------------------------------"<<endl;
        cout<<"1-Add a Node"<<endl;
        cout<<"2-Delete a Particular Node"<<endl;
        cout<<"3-Show the # of items"<<endl;
        cout<<"4-Show all Linked List"<<endl;
        cout<<"5-Exit "<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
                //Case 1 is intended to prompt the user for a number to input to the beginning of the list.
            case 1:
                int item;
                cout << "Inserting Node at Beginning: " <<  endl;
                cout << endl << "What number would you like to input?" << endl;
                cin >> item;
                sl.addnew(item);
                cout<<endl;
                break;
                //Case 2 deletes the head node, by using the deleteitem() function.
            case 2:
                cout << endl << "Deleting a node: " << endl;
                sl.deleteitem();
                break;
                //Case 3 prompts the shownumber() function to count the nodes.
            case 3:
                cout << endl << "# of items in linked list: " << endl;
                sl.shownumber();
                cout << endl;
                break;
                //Case 4 calls showall() function to print all the nodes.
            case 4:
                cout << endl << "Display elements of link list"<<endl;
                sl.showall();
                cout << endl;
                break;
                //Case 5 closes the program
            case 5:
                cout << endl << "Exiting the program" << endl;
                return 0;
                break;
                //Default case is for wrong entries and prompts user for another input.
            default:
                cout << "Wrong choice" << endl;
        }
        cout << endl;
        
    }
    return 0;
}
