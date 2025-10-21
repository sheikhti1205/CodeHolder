#include <stdio.h>
#include <conio.h>
int main()
{
    int x = 3;
    int y = 4;

    x = x * y; //12
    y = x / y; // 12 divided by 4 equals 3
    x = x / y; // 12 divided by 3 equals 4

    printf("X is %d & Y is %d", x, y);

    return 0;
}