#include <stdio.h>
#include <math.h>
int main()
{
    float x, f, g;

    printf("Enter the value of x: \n");
    scanf("%f", &x);

    f = (3 * (x * x * x * x));
    f = f + (2 * sqrt(x) - 2);

    g = (5 * (f * f * f)) - 4;

    printf("The calculated value of g{f(x)} is %.2f\n", g);

    return 0;
}