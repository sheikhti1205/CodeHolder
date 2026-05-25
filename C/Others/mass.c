#include <stdio.h>
int main()
{
    float p, v, m, t;

    printf("Enter the Pressure & Volume of the tire: \n");
    scanf("%f%f", &p, &v);

    printf("Enter the temperature you want to measure the value of mass: \n");
    scanf("%f", &t);

    m = (p * v) / (0.37 * (t + 460)); //pv = 0.37m(t + 460)

    printf("The mass of the air inside the tire is: %f\n", m);

    return 0;
}