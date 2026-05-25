#include <stdio.h>
#include <unistd.h>
int main()
{
    int s,a;
    char c;
    do{
    printf("Enter Your Total Savings:\n");
    scanf("%d", &s);
    printf("Is this your total savings?\n");
    
    for(a=0; a<6; a++)
    {
        printf("."); sleep(1);
    }
        printf("Confirm?");
        scanf("%c", &c);
    }
    while(c!= 'y' || 'Y');

}