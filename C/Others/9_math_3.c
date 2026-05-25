#include <stdio.h>
#include <math.h>
int main () {

    double A;
    double B;
    double C;

    printf("\nEnter A :");
    scanf("%lf", &A);
    printf("\nEnter B :");
    scanf("%lf", &B);

    C = sqrt(A*A + B*B);
    printf("\nC is = %.5lf\n", C);

    return 0;
}

    