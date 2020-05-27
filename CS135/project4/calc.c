//Name: Joshua Insorio
//Date: 3.5.18
//Project 4: calc.c
//Purpose: Write an interactive program that implements a simple calculator. 


#include <stdio.h>
#include <math.h>

int main(void)
{
    int choice, first_numi, second_numi, mode = 1;
    double first_numd, second_numd;

    printf("This program implements a calculator\n");
    printf("Options: \n1 - addition\n2 - subtraction\n3 - multiplication\n4 - division\n5 - toggle calculator type\n6 - exit program\n");
    printf("Please enter your option: ");
    scanf("%d", &choice);

while(choice == 0 || choice > 6)
    {
        printf("Invalid Option.\n");
        printf("Options: \n1 - addition\n2 - subtraction\n3 - multiplication\n4 - division\n5 - toggle calculator type\n6 - exit program\n");
        printf("Please enter your option: ");
        scanf("%d", &choice);

    }

while((choice < 7) && (choice > 0))
    {
        if(mode == 1)
        {
            switch(choice)
                {
                case 1:
                    printf("Enter first term:"); 
                    scanf("%lf", &first_numd);
                    printf("Enter second term:"); 
                    scanf("%lf", &second_numd);
                    printf("The sum is: %.15lf\n", first_numd + second_numd);
                    break;
                case 2:
                    printf("Enter first term:"); 
                    scanf("%lf", &first_numd);
                    printf("Enter second term:"); 
                    scanf("%lf", &second_numd);
                    printf("The sum is: %.15lf\n", first_numd - second_numd);
                    break;
                case 3:
                    printf("Enter first term:"); 
                    scanf("%lf", &first_numd);
                    printf("Enter second term:"); 
                    scanf("%lf", &second_numd);
                    printf("The sum is: %.15lf\n", first_numd * second_numd);
                    break;
                case 4:
                    printf("Enter first term:"); 
                    scanf("%lf", &first_numd);
                    printf("Enter second term:"); 
                    scanf("%lf", &second_numd);
                    if(second_numd == 0)
                        {
                        printf("Cannot divide by zero!\n");
                        break;
                        }
                    printf("The sum is: %.15lf\n", first_numd / second_numd);
                    break;
                case 5:
                    printf("Calculator now works with integers.\n");
                    mode = 0;
                    break;
                case 6:
                    return 0;
                }
        }
        else if(mode == 0)
        {
            switch(choice)
                {
                case 1:
                    printf("Enter first term:"); 
                    scanf("%d", &first_numi);
                    printf("Enter second term:"); 
                    scanf("%d", &second_numi);
                    printf("The sum is: %d\n", first_numi + second_numi); 
                    break;
                case 2:
                    printf("Enter first term:"); 
                    scanf("%d", &first_numi);
                    printf("Enter second term:"); 
                    scanf("%d", &second_numi);
                    printf("The sum is: %d\n", first_numi - second_numi);
                    break;
                case 3:
                    printf("Enter first term:"); 
                    scanf("%d", &first_numi);
                    printf("Enter second term:"); 
                    scanf("%d", &second_numi);
                    printf("The sum is: ß%d\n", first_numi * second_numi);
                    break;
                case 4:
                    printf("Enter first term:"); 
                    scanf("%d", &first_numi);
                    printf("Enter second term:"); 
                    scanf("%d", &second_numi);
                    if(second_numd == 0)
                        {
                        printf("Cannot divide by zero!\n");
                        break;
                        }
                    printf("The sum is: %d\n", first_numi / second_numi);
                    break;
                case 5:
                    printf("Calculator now works with doubles.\n");
                    mode = 1;
                    break;
                case 6:
                    return 0;
                }
        }
    printf("Options: \n1 - addition\n2 - subtraction\n3 - multiplication\n4 - division\n5 - toggle calculator type\n6 - exit program\n");
    printf("Please enter your option: ");
    scanf("%d", &choice);

    }









    return 0;
}