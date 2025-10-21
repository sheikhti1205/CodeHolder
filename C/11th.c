#include <stdio.h>
#include <math.h>
int main()
{
    float a, b, c, d, m;

    printf("Enter the value of a, b, c, d: \n");
    scanf("%f%f%f%f", &a, &b, &c, &d);

    m = sqrt( pow( (a-b), 2) / pow( (c+ (4*d) ), 2));

    m = m + sqrt(sqrt((a - b / c + d)));

    printf("The solve of the given equation is: %f\n", m);

}