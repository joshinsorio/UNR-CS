/*header
#include <stdio.h>

int main(void)
{
    int height = 8, width = 12, depth = 10;
    int volume;
    int dimensional_weight;

    volume = height * width * depth;
    dimensional_weight = volume/166;

    printf("Dimensions: %dx%dx%d\n", depth, width, height);
    printf("Volume (cubic inches) %d\n", volume);
    printf("Dimensional weight (pounds): %d\n", dimensional_weight);
    return 0;


}

*/


//Code #2, improvement of last code
#include <stdio.h>

#define INCHES_PER_POUND 166
#define ROUND_UP_OFFSET (INCHES_PER_POUND - 1)

int main(void)
{
    int height, width, depth, volume, weight;

    printf("Enter the height ");
    scanf("%d", &height);

    printf("Enter the depth ");
    scanf("%d", &depth);

    printf("Enter the width ");
    scanf("%d", &width);

    volume = height * width * depth;
    weight = (volume + ROUND_UP_OFFSET) / INCHES_PER_POUND;

    printf("Volume (cubic inches): %d\n", volume);
    printf("Dimensional Weight (pounds): %d\n", weight);

    return 0;

}