#include <stdio.h>


int main(void)
{
    int sum1, sum2, total, check_digit, a, b, c, d, e, f, g, h, i, j, k;

    printf("Enter the first (single) digit: ");
    scanf("%d", &a);
    printf("Enter first group of five digits: ");
    scanf("%1d%1d%1d%1d%1d", &b, &c, &d, &e, &f);
    printf("Enter second group of five digits: ");
    scanf("%1d%1d%1d%1d%1d", &g, &h, &i, &j, &k);

    sum1 = a + c + e + g + i + k;
    sum2 = b + d +f + h + j;
    total = (sum1 * 3 + sum2) - 1;
    check_digit = 9 - (total%10);

    printf("Check digit: %d\n", check_digit);



    return 0;
}
