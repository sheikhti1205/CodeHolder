#include <stdio.h>
#include <math.h>
int main()
{
    float x, t, m;

    printf("Enter the value of x & t: \n");
    scanf("%f%f", &x, &t);

    m = ( (24*t) - (10*t) ) / ( sqrt((x*t)) + 100);
    m = sqrt(m);
    m = m + pow(( (3*t) / (6*(t*t)) ), 2);

    printf("The value of m is: %f", m);

    return 0;
}