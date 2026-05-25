#include <stdio.h>
int main()
{
    float a = 50;

    a = a++ / a;

    printf("%d", a);
}