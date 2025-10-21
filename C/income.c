#include <stdio.h>
int main()
{
    float hour, gross, rate, net, bon, tax;

    printf("How many hours have you worked today? : \n");
    scanf("%f", &hour);

    printf("What's the hourly rate you're paid at? : \n");
    scanf("%f", &rate);

    gross = hour * rate;
    tax = gross * 0.05;
    bon = gross * 0.07;

    printf("Your gross payment is: %f\n", gross);

    net = (gross + bon) - tax;

    printf("Your net payment is: %f\n", net);

    return 0;
}