#include <stdio.h>
int main()
{
    char ch;

    printf("Enter a character: \n");
    scanf("%c", &ch);

    switch (ch)
    {
        default :
            printf("This is not a vowel!\n");
            break; 
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            printf("This is a vowel!\n");
            break;
        
    }
}