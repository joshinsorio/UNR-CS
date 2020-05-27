//Name: Joshua Insorio 
//Date: 2/20/17
//project 3: sq_root_c.c
//Function: Challenge for sq_root.c

#include <stdio.h>
#include <math.h>

int main (void)
{
    float number, guess, new_guess, old_guess;
    int counter = 0;

    printf("Enter a number: ");
    scanf("%f", &number);
    old_guess = 1;



    while (fabs((guess * guess) - number) > 1e-5 )
    {  
        printf("%d\t%10.5f\n", counter, old_guess);
        old_guess = (old_guess + (number / old_guess)) / 2.0;
        guess = old_guess;
        counter++;
        
    }
   printf("Estimated square root of %0.5f: is %0.5f\n", number, old_guess);
    return 0;
}