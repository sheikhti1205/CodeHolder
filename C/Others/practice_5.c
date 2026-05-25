#include <stdio.h>
int main()
{
    char *p = 0;
    *p = 'A';
    //trying to write to memory address 0 which won't work.
    printf("Value of *p is: \n", *p);
}