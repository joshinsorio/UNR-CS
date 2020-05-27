//Name: Joshua Insorio
//Date: 3.14.18
//Project 5: arrays.c
//Purpose: Write a program that asks the user to enter an NxM dimensional array containing single digit values (only the digits between 0 and 9) and counts the number of times each one of the 10 digits appears in the array.


#include <stdio.h>

int main(void)
{

    int N, M;

    printf("This program counts occurances of digits 0 through 9 in an NxM array.\n");
    printf("Enter the size of the array (Row Column): ");
    scanf("%d %d", &N, &M);

    int array[N][M];
    for(int rows = 0; rows < N ; rows++)
    {
        printf("Enter row %d: ", rows);
        for(int columns = 0;columns < M; columns++)
        {
            scanf("%d", &array[rows][columns]);
            
        }
    
    }

    int digit_seen[10] = {0};

    for(int rows = 0; rows < N ;rows++ )
    {
        for(int columns = 0, digit; columns < M ; columns++)
        {
            digit = array[rows][columns];
            digit_seen[digit]++;
            
        }
    }   

    int n = 0, j = 0;
    while(n <= 9)
    {
        printf("Digit %d occurs %d times\n", n, digit_seen[n]);
        n++;
    }


    printf("The digit counts directly from the 1D array:\n");
    while(j <= 9)
    {
        printf("%d ", digit_seen[j]);
        j++;
    }
    printf("\n");

    printf("The original 2D array entered by the user:\n");
    for(int rows = 0 ;rows < N ;rows++ )
    {
        for(int columns = 0;columns < M ; columns++)
        {
            printf("%d ", array[rows][columns]);
        }
        printf("\n");

    }


    return 0;
}