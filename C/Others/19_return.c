#include <stdio.h>

double square(double x) {
    return x * x;
}

int main() {
    double x = square(3.14);
    printf("\nThe square of PI is %.3lf.", x);

    return 0;
}