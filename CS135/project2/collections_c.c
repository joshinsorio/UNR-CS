//Name: Joshua Insorio 
//Date: 2/14/17
//project 2: collections_c.c
//Function: Challenge for collections.c

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int budget, volume1, volume2, volume3, volume_price1, volume_price2, volume_price3, collection1, collection2, collection3;

    printf("Enter volumes and price per volume for collection 1: ");
    scanf("%d %d", &volume1, &volume_price1);
    printf("Enter volumes and price per volume for collection 2: ");
    scanf("%d %d", &volume2, &volume_price2);
    printf("Enter volumes and price per volume for collection 3: ");
    scanf("%d %d", &volume3, &volume_price3);
    printf("Enter Bob's budget: ");
    scanf("%d", &budget);

    collection1 = volume_price1 * volume1;
    collection2 = volume_price2 * volume2;
    collection3 = volume_price3 * volume3;


    if ( budget > 0  )
        printf("(1) Bob has some money to buy collections.\n");
        else 
        printf("(1) Bob does not have enough money to buy anything.\n");
    if ( budget > (collection1 + collection2 + collection3) )
        printf("(2) Bob has enough money to buy all three collections.\n");
        else
        printf("(2) Bob does not have enough money to buy all three collections.\n");
    if ( (budget <= collection1 && collection2) || (budget <= collection1 && collection3) || (budget <= collection2 && collection3))
        printf("(3) At least two collections are more expensive than Bob's budget.\n");
        else 
        printf("(3) At least two collections are cheaper than or equal to Bob's budget.\n");
    if ( collection1 == collection2 || collection1 == collection3 || collection2 == collection3)
        printf("(4) At least two collections cost the same amount of money.\n");
        else
        printf("(4) No two collections have the same price.\n");
    if ( ((budget <= collection1) && (budget <= collection2)) || ((budget <= collection1) && (budget <= collection3)) || ((budget <= collection2) && (budget <= collection3)) )
        printf("(5) Only one collection is cheaper than or equal to Bob’s budget.\n");
        else
        printf("(5) More than one collection is cheaper than or equal to Bob’s budget or they are all more expensive.\n");    
    if ( (budget >= collection1) && (budget >= collection2) && (budget >= collection3) )
        printf("(6) Bob has enough money to buy any one of the three collections.\n");
        else
        printf("(6) Bob does not have enough money to buy any one of the three collections \n");
    if ( (budget <= collection1) || (budget <= collection2) || (budget <= collection3) )
        printf("(7) Bob does not have enough money to buy any collection.\n");
        else
        printf("(7) Bob can buy at least one collection.\n");
        
    return 0;
}