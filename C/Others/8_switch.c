#include <stdio.h>
#include <stdlib.h>
int main()
{
    int choice;
    printf("Express Your Dissatisfaction With C in 1-3\nWhere 1 = Very Little, 2 = Good Amount, 3 = A Lot!\n");
    scanf("%d", &choice);
//int i = 0;
    switch(choice)
    {
        case 1:
            printf("Your are Very Little dissatisfied with C?\nSeriously?\n");
            break;
        case 2:
            printf("You're just dissatisfied to this extent only?\nNow I'm Dissapointed in you!\n");
            break;
//we can have as many cases we want!
        case 3:
            printf("Good!\nWe have a similar opinion about C!\n");
            break;
        default:
//not necessary but good to have!
            printf("What the hell did you type!?\nCan't You TYPE a simple number between 1 to THREE!?\n");
    }
}