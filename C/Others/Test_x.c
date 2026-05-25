#include <stdio.h>
#include <unistd.h>

void work();
void animation();

int main()
    {
    work();

    return 0;
    }



void work()
{
    int x, y, z, i;
    char a;

    printf("Assume a number X\n\nDone?\n\nEnter any letter to continue.\n\nEnter n to exit\n");

    scanf(" %c", &a);

    if(a == 'n' || a == 'N')
    {
        printf("Program Terminated\n");
    }
    else
    {
        printf("\nMultiply the number by 2\n");

        printf("\nNow add a number which is even\n\nEnter the number you choose to add\n");
        scanf("%d", &y);

        printf("\nEnter the total number\n");
        scanf("%d", &z);

        x = (z / 2) - (y / 2);
    

    animation();

    printf("Guessed number is: %d.\n", x);
    }
}

void animation()
{
        printf("Please wait!\n");

        for (int i = 0; i < 5; i++) 
        {
        printf("/"); fflush(stdout); sleep(1);
        printf("\b\\"); fflush(stdout); sleep(1);
        printf("\b|"); fflush(stdout); sleep(1);
        printf("\b-"); fflush(stdout); sleep(1);
        }

        printf("\b \n");  // To clean up the last character
        printf("Done!\n");
}