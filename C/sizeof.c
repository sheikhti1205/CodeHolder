#include <stdio.h>
int main()
{
    if(sizeof(int) > -1) //-1 is unsigned int size is very large
    //we're comparing the size of int and unsigned int
    // not something else
    // int size is 4
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }

}