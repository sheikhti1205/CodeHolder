#include <stdio.h>
#include <math.h>
int main()
{
    float x1, x2, y1, y2;
    float x, y, z, D;

    printf("Enter the value of x1, x2, y1, y2 one by one: \n");
    scanf("%f%f%f%f", &x1,&x2,&y1,&y2);

    x = x2 - x1; y = y2 - y1;
    x = pow(x , 2); y = pow(y , 2);
    z = (x + y);
    D = sqrt(z);

    printf("D is %.3f", D);

    return 0;
}