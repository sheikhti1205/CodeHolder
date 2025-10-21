#include <stdio.h>
int main()
{
    int marks=83;

    (marks > 75) ? printf("First Class\n") : 
    (marks > 65) ? printf("Second Class\n") : 
    (marks > 55) ? printf("Third Class\n") : printf("Fourth Class\n");

    return 0;
}