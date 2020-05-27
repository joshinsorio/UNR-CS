//Name: Joshua Insorio 
//Date: 2/20/17
//project 3: series.c
//Function: Write a program that asks the user to enter an integer number, n, and computes the provided mathematical series

#include <math.h>
#include <stdio.h>

int main(void){

    int n, c = -1, value, k, total;

    printf("Enter an integer number: ");
    scanf("%d", &n);

    for (k = 1; k <= n ; k++)
    {
        value = pow(c,k+1) * pow(k,2);
        total += value;
        
        
    }
    printf("The value of the series is: %d\n", total);

    return 0;
}