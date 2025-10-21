#include <stdio.h>
int main()
{
    int num = 0, reverse = 0, remainder = 0;
    printf("Enter your value to reverse: \n");
    scanf("%d", &num);

    while(num != 0)
    {
        int remainder = num % 10;
        reverse = reverse * 10 + remainder;
        num /= 10;
    }

    printf("%d\n", reverse);

    return 0;
}