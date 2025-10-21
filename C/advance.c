#include <stdio.h>
int main()
{
    int a, b = 1, c = 1;

    a = sizeof(c = ++b + 1);
    //c is int and int size is 4
    // a = 4
    //c =and b remains same
    //size of gets the size of int c
    // but the work inside doesn't happen
    printf("a = %d, b = %d, c = %d\n", a, b, c);
    
}