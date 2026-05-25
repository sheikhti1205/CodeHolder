#include <stdio.h>
int main()
{
    printf("\t\tASCII value of any character::--\n");

    char ch;
    printf("Input any character::-- \n");
    scanf("%c", &ch);
    printf("ASCII value of %c is: %d\n", ch,ch);
    //Printing in %d format makes a character which is in %c print out in ASCII form
}