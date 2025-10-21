#include <stdio.h>

int main()
{
    int i = -5; i = (i < 0) ? -i : i;

    //assigning positive value in case of negative value

    printf("%d", i);
}