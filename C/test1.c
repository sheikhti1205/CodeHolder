#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c, x1, x2, x;

    printf("Enter The Value Of a, b, c respectively: \n");
    scanf("%lf%lf%lf", &a, &b, &c);
    
    if(a == 0 && b == 0)
    {
        printf("Error!\n");
    }
    else if(a == 0 && b != 0)
    {
        x = -(c / b);
        printf("There is only one root\n x equals to %0.2lf\n", x);
    }
    else if((b*b - (4*a*c) < 0))
    {
        printf("There are no real roots\n");
    }
    else
    {
        printf("There are two real roots\n");
    }

    x1 = -b + (sqrt((b*b) - (4*a*c) / 2*a));
    x2 = -b - (sqrt((b*b) - (4*a*c) / 2*a));

    printf("The value of x1 is %lf & the value of x2 is %lf", x1, x2);

    return 0;
}