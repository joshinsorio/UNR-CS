//
//  delimiters.cpp
//  proj2
//
//  Created by Joshua Insorio on 2/19/19.
//  Copyright Â© 2019 Joshua Insorio. All rights reserved.
//
//--------------------------------------------------------------------
//
//   delimiters.cpp
//
//--------------------------------------------------------------------

#include <iostream>
#include <string>
#include "StackLinked.h"
using namespace std;



//--------------------------------------------------------------------

bool delimitersOk (const string & expression);

//--------------------------------------------------------------------

int main()
{
    
    string inputLine;            // Input line
    char   ch;                   // Holding pen for input chars
    
    cout << "This program checks for properly matched delimiters."
    << endl;
    
    while( cin )
    {
        cout << "Enter delimited expression (<EOF> to quit) : "
        << endl;
        
        // Read in one line
        inputLine = "";
        cin.get(ch);
        while( cin && ch != '\n' )
        {
            inputLine = inputLine + ch;
            cin.get(ch);
        }
        
        if( ! cin )              // Reached EOF: stop processing
            break;
        
        if ( delimitersOk (inputLine) )
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }
    return 0;
}

//--------------------------------------------------------------------
// delimitersOk: the function that students must implement for
//    Programming Exercise 3.
// Note: we used the term "braces" to describe '[' and ']'. It would
//    have been better to use the term "brackets". The program can be
//    easily modified to process any set of matching delimiters.
//--------------------------------------------------------------------

// Insert your delimitersOk function below
bool delimitersOk (const string & expression)
{
    StackLinked<char> stack;
    char temp;
    try
    {
        //Loop to go through all the whole expression
        for(unsigned int i = 0; i < expression.length(); i++)
        {
            //Find the opening delimiter
            if((expression[i] == '(')||(expression[i] == '{')||(expression[i] == '<')||(expression[i] == '['))
            {
                stack.push(expression[i]);
            }
            //Try to find the corresponding closing delimiter
            else if((expression[i] == ')'))
            {
                temp = stack.pop();
                if((temp != '('))
                {
                    return false;
                }
            }
            else if((expression[i] == '}'))
            {
                temp = stack.pop();
                if((temp != '{'))
                {
                    return false;
                }
            }
            else if((expression[i] == '>'))
            {
                temp = stack.pop();
                if((temp != '<'))
                {
                    return false;
                }
            }
            else if((expression[i] == ']'))
            {
                temp = stack.pop();
                if((temp != '['))
                {
                    return false;
                }
            }
        }
        //Return true if there is nothing inside
        return stack.isEmpty();
    }catch(logic_error)
    {
        return false;
    }
}

