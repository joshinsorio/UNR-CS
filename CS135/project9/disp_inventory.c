//Name: Joshua Insorio
//Date: 4.30.18
//Project 9: disp_inventory.c
//Purpose: Write a program to read information from the inventory.txt file and display it to the screen
#include <stdio.h>

int main(int argv, char *argc[])
{  
	FILE *fp;
	fp = fopen("inventory.txt", "rb+");
	if(fp == NULL)
	{
		return 0;
	}
	
	int number, quantity;
	float price;
	printf("Below are the items in your inventory.\n");
    printf("Part#\tQuantity\tItem Price\n");
    int c = 1;
	while(1)
	{
		
        fread(&number, sizeof(int), 1, fp);
        fread(&quantity, sizeof(int), 1, fp);
        fread(&price, sizeof(float), 1, fp);

        if (number == 0)
        {
            break;
        }
        printf("%5d\t", number);
        printf("%8d\t", quantity);
        printf("%9.2f\n", price);
			
	}

	fclose(fp);
	return 0;
}