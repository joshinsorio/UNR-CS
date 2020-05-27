//Name: Joshua Insorio 
//Date: 2/5/17
//project 1: circle.c
//Function: Ask the user for the radius of a circle that has been inscribed in a square, and then will calculate and print out: the diameter of the circle, the circumference of the circle, the area of the circle, the perimeter of the square, the area of the square, and the difference between the area of the square and the area of the circle. 

#include <stdio.h>

#define pi 3.14f

int main(void)
{
    int area, perimeter, diameter, area_square, radius; 
    float difference, circumference, area_circle;

    printf("Enter the value of the radius: ");
    scanf ("%d", &radius);
    diameter = radius * 2;
    circumference = 2 * pi * radius;
    perimeter = diameter * 4;
    area_circle = pi * (radius * radius);
    area_square = diameter * diameter; 
    difference = area_square - area_circle;

    printf("The diameter of the circle is: %d\n", diameter);
    printf("The circumference of the circle is: %0.3f\n", circumference);
    printf("The area of the circle is: %0.3f\n", area_circle);
    printf("The perimeter of the square is: %d\n", perimeter);
    printf("The area of the square is: %d\n", area_square);
    printf("The difference between the area of the square and the circle is: %0.3f\n", difference);


    return 0;
}


