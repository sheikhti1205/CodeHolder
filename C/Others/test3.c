#include <stdio.h>
#include <ctype.h>

int main()
{
    char userinput1, userinput2;

    printf("Enter player one choice: \n");
    scanf("%c", &userinput1);
    getchar();
    printf("Enter player two choice: \n");
    scanf("%c", &userinput2);

    if(isupper(userinput1))
    {
         userinput1 = tolower(userinput1);
    }
    if(isupper(userinput2))
    {
        userinput2 = tolower(userinput2);
    }

    if(userinput1 == 'r' && userinput2 == 'p')
    {
        printf("Player two Wins!\n");
    }
    else if(userinput1 == 'p' && userinput2 == 's')
    {
        printf("Player two Wins!\n");
    }
    else if(userinput1 == 'r' && userinput2 == 's')
    {
        printf("Player two Wins!\n");
    }
    else if(userinput2 == 'r' && userinput1 == 'p')
    {
        printf("Player one Wins!\n");
    }
    else if(userinput2 == 'p' && userinput1 == 's')
    {
        printf("Player one Wins!\n");
    }
    else if(userinput2 == 'r' && userinput1 == 's')
    {
        printf("Player one Wins!\n");
    }
    else
    {
        printf("wrong input!\n");
    }

    return 0;
}