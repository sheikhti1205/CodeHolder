#include <stdio.h>
int main()
{
    int i;
    for(i = 0; i < 5; i++);
    printf("Hello world: %d", i);
    //the for loop exits only after the condition i < 5 fails.
    //thus we get i = 5 not 4;
}