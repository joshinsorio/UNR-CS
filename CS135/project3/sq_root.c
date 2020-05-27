//Name: Joshua Insorio 
//Date: 2/20/17
//project 3: sq_root.c
//Function: Write a program to guess the square root of a number

#include <stdio.h>
#include <math.h>

int main (void)
{
    double number, guess, new_guess, old_guess;

    printf("Enter a number: ");
    scanf("%lf", &number);
    old_guess = 1;



    while (fabs((guess * guess) - number) > 1e-5 )
    {  
        printf("%10.5lf\n", old_guess);
        old_guess = (old_guess + (number / old_guess)) / 2.0;
        guess = old_guess;
        
    }
   printf("Estimated square root of %10.5lf: is %10.5lf\n", number, old_guess);
    return 0;
}