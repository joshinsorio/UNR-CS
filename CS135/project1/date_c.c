//Name: Joshua Insorio
//Date: 2/5/17
//project 1: date_c.c
//Function: Challenge for date.c


#include <stdio.h>

int main(void)
{

    int d1 , d2, d3, d4, m1, m2, m3, m4, y1, y2, y3, y4;

    printf("Enter date 1 (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &d1, &m1, &y1);

    printf("Enter date 2 (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &d2, &m2, &y2);

    printf("Enter date 3 (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &d3, &m3, &y3);

    printf("Enter date 4 (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &d4, &m4, &y4);

    printf("Year\tMonth\tDay\n%4d\t%2.2d\t%2.2d\n%4d\t%2.2d\t%2.2d\n%4d\t%2.2d\t%2.2d\n%4.4d\t%2.2d\t%2.2d\n", y1, m1, d1, y2, m2, d2, y3, m3, d3, y4, m4, d4);

    return 0;
}
