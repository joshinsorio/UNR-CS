//Name: Joshua Insorio
//Date: 2.8.18
//project 9: save_inventory_c.c
//Purpose: Challenege for save_inventory.c

#include <stdio.h>
void checker(int number, int *array);

int main(int argv, char *argc[])
{
	FILE *fp;
	fp = fopen("inventory.txt", "wb+");
	if(fp == NULL)
	{
		return 0;
	}

    int number, quantity;
    int array[20], i = 0;
    float price;
	printf("This program stores a business inventory.\n");
	do
	{
		printf("Please enter item data (part number, quantity, price): ");
        scanf("%d, %d, %f", &number, &quantity, &price);
        if(number == 0)
        {
            break;
        }
        array[i] = number;
        i++;
        checker(number, array);
        fwrite(&number, sizeof(int), 1, fp);
        fwrite(&quantity, sizeof(int), 1, fp);
        fwrite(&price, sizeof(float), 1, fp);
		
        fflush(stdin);
	}while(number != 0);
    printf("Thank you. Inventory stored in file inventory.txt\n");

	fclose(fp);
	return 0;
}

void checker(int number, int *array)
{
    int counter = 1;
    for(;*array != '\0'; array++)
    {   
        if(*array == number)
        {
            counter += 1;
        }

    }
    if(counter > 2)
     {
        printf("The item has been entered before.\n");
    }
}