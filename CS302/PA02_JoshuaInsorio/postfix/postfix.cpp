//
//  postfix.cpp
//  proj2
//
//  Created by Joshua Insorio on 2/18/19.
//  Copyright © 2019 Joshua Insorio. All rights reserved.
//

#include <iostream>
#include <string>
#include "postfix.h"
using namespace std;
using std::string;

//Function declarations
bool isOperator(const char c);
int precedence( const char x, const char y );
void infixToPostfix(string infix);
void evaluate(string pfx);


int main()
{
    string inFix = "";
    //cout <<"\n\t" << "Program that converts an infix expression" << "\n\t" << "into an equivalent postfix expression";
    cout <<"\n\t" << "Program that evaluates an postfix expression" << "\n\t";
    cout << "\n\n\t"<< "Please enter an expression without spaces: ";
    cin >> inFix;
    evaluate(inFix);
    //infixToPostfix(inFix);
    cout << "\n\n\t";//calculate here
    return 0;
}



//Function to determine wether the char passed inside is an operator or not
bool isOperator(const char c)
{
    
    if ((c == '+')||(c == '-')||(c == '*')||(c == '/')||(c == '^')||(c == '%'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Function determining the weights of the two operands passed in.
//The weights increase depending on the the precendence according to PEMDAS
int precedence( const char x, const char y )
{
    int pre1 = 0, pre2 = 0;
    
    if(x == '^')
    {
        pre1 = 2;
    }
    else if(x == '*' || x == '/')
    {
        pre1 = 1;
    }
    else if(x == '+' || x == '-')
    {
        pre1 = 0;
    }
    if(y == '^')
    {
        pre2 = 2;
    }
    else if(y == '*' || y == '/')
    {
        pre2 = 1;
    }
    else if(y == '+' || y == '-')
    {
        pre2 = 0;
    }
    
    if (pre1 == pre2)
    {
        return 0;
    }
    else
    {
        if (pre1 > pre2)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    
}


//Function to set infix to postfix
void infixToPostfix(string infix)
{
    //Creates the stack
    stackType<char> myStack;
    string pfx = "";
    cout << "\n\t" << "The infix expression is: " <<infix;
    infix.append( ")" );
    myStack.push( '(' );
    unsigned int i = 0;
    
    //Loop through deciding if the char passed is an operator or not
    for(; i < infix.length();)
    {
        //If an operator is found calculate the precedence.
        if (isOperator(infix[i]))
        {
            if (isOperator(myStack.top()))
            {
                switch(precedence(infix[i], myStack.top()))
                {
                    case 1:
                        myStack.push( infix[i] );
                        i++;
                        break;
                        
                    case 0:
                        pfx = pfx + myStack.top();
                        myStack.pop();
                        break;
                        
                    case -1:
                        pfx = pfx + myStack.top();
                        myStack.pop();
                        break;
                }
            }
            else
            {
                
                myStack.push(infix[i]);
                i++;
            }
        }
        //If infix is not an operator, push and add the values into the postfix string
        else
        {
            switch(infix[i])
            {
                case ')':
                    while (myStack.top() != '(')
                    {
                        pfx = pfx + myStack.top();
                        myStack.pop();
                    }
                    myStack.pop();
                    i++;
                    break;
                    
                case '(':
                    myStack.push( infix[i] );
                    i++;
                    break;
                    
                default:
                    pfx = pfx + infix[i];
                    i++;
                    break;
                    
            }
        }
    }
    //Output the result of the conversion and then calls the evaluate function to calculate the result
    cout << "\n\t" << "The postfix expression is: " << pfx << "\n\n\t";
    evaluate(pfx);
}

//Function to evaluate the postfix expression
void evaluate(string pfx)
{
    stackType<int> stack;
    unsigned int i = 0;
    for(;i < pfx.length(); i++ )
    {
        //Converting all the numbers in the string to int and pushing them into the stack
        if(isOperator(pfx[i]) == false)
        {
            int temp = pfx[i] - '0';
            stack.push(temp);
        }
        else
        {
            //Setting operands to when it finds the operator
            int operand1 = stack.top();
            stack.pop();
            int operand2 = stack.top();
            stack.pop();
            
            //Calculates the result and initializes it into "result" depending on the operator
            int result = 1;
            switch(pfx[i])
            {
                case '+':
                    result = operand2 + operand1;
                    break;
                    
                case '-':
                    result = operand2 - operand1;
                    break;
                    
                case '*':
                    result = operand2 * operand1;
                    break;
                    
                case '/':
                    result = operand2 / operand1;
                    break;
                    
                case '^':
                    for(int i = 0; i < operand1; i++)
                    {
                        result *= operand2;
                    }
                    break;
                    
                default:
                    throw logic_error("Invalid operator");
                    break;
            }
            stack.push(result);
        }
    }
    //Output the result of the calculation
    cout << "\n\t" << "The evaluation of the expression is: " << stack.top() << "\n\n\t";
}
