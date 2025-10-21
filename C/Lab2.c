#include <stdio.h>
int main()
{
    float tot, fix, fin, bon, tax;

    printf("Enter total sale: \n");
    scanf("%f", &tot);
    printf("Enter fixed salary: \n");
    scanf("%f", &fix);

    bon = tot * 0.15;

    tax = fix * 0.12;

    fin = (fix + bon) - tax;

    printf("The final slary is: %.2f\n", fin);

    return 0;
}