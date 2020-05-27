#include <stdio.h>


int main(void)
{
    int first_fraction_num, second_fraction_num, first_fraction_den, second_fraction_den, sum, f_top, f_bot;
    

    printf("Enter first fraction(#/#): ");
    scanf("%d/%d", &first_fraction_num, &first_fraction_den);
    printf("Enter second fraction: ");
    scanf("%d/%d", &second_fraction_num, &second_fraction_den);

    f_bot = second_fraction_den * first_fraction_den;
    f_top = (first_fraction_num * second_fraction_den) + (second_fraction_num * first_fraction_den);
    


    printf("The sum of the two fractions is: %d/%d\n", f_top, f_bot);

    return 0;
}
