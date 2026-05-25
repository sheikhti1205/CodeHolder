#include <stdio.h>

int printArray();

int main()
{
    int b[] = {4, 6, 8, 10};
    printArray(b);
}
int printArray(int z[])
{
    printf("%d", z[0]);
}