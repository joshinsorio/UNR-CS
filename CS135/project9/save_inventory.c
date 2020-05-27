//Name: Joshua Insorio
//Date: 2.8.18
//project 9: save_inventory.c
//Purpose: Write a program to repeatedly ask the user to enter information regarding inventory for a business (item part
//number, quantity, price) and then saves the information to a file called inventory.txt.

#include <stdio.h>

int main(int argv, char *argc[])
{
	FILE *fp;
	fp = fopen("inventory.txt", "wb+");
	if(fp == NULL)
	{
		return 0;
	}

    int number, quantity;
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
        fwrite(&number, sizeof(int), 1, fp);
        fwrite(&quantity, sizeof(int), 1, fp);
        fwrite(&price, sizeof(float), 1, fp);
		
        fflush(stdin);
	}while(number != 0);
    printf("Thank you. Inventory stored in file inventory.txt\n");

	fclose(fp);
	return 0;
}