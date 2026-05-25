#include <stdio.h>
int main () {
    //switch = a more efficient alternative to using many "else if" statements,
    //allows a value to be tested for equality against many cases.
    /*ok?*/

    char grade;

    printf("Enter your grade\n");
    scanf("%c", &grade);

    switch(grade) {
        case 'A':
        case 'a':
           printf("\nperfect!\n");
           break;
        case 'B':
        case 'b':
           printf("\nYou did great!\n");
           break;
        case 'C':
        case 'c':
           printf("\nOK!\n");
           break;
        case 'D':
        case 'd':
           printf("\nFine I guess...\n");
           break;
        case 'E':
        case 'e':
           printf("\nAt least not an F!\n");
           break;
        case 'F':
        case 'f':
           printf("\nYou failed!\n");
           break;
        default:
           printf("\nPlease enter a valid grade!\n");
           break;
    }

    return 0;
   
}