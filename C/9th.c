#include <stdio.h>
#include <math.h>
int main()
{
    float x, f, g;

    printf("Enter the value of x: \n");
    scanf("%f", &x);

    g = (7 * x) - 6;

    f = 4 * (g * g);
    f = f + (2 * sqrt(g) - 3);

    printf("The calculated value of f{g(x)} is %.2f\n", f);

    return 0;
}