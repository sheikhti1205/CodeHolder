#include <stdio.h>
int main()
{
    int num = 0, remainder = 0, reversed = 0, original;
    char yorn;

    do
    {   
    printf("Enter Your Value: ");
    scanf("%d", &num);

    original = num;

    while(num != 0)
    {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }

    printf("Original is %d\nReversed is %d\n", original, reversed);

    if(reversed == original)
    {
        printf("\nThis number is a palindrome number\n");
    }
    else
    {
        printf("\nThis number isn't a palindrome number\n");
    }

    printf("Do you want to test another number? Y or N\n");
    scanf(" %c", &yorn);

    num = 0;
    reversed = 0;

    } while (yorn == 'Y' || yorn == 'y');
}