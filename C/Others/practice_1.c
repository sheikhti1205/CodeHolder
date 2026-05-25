#include <stdio.h>
int main()
{
    int x = printf("Hello\n");
    printf("%d", x);  // Escape sequences are not counted!! so instead of 7 it would be 6!! (n will be counted)
}