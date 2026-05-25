#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("Enter Your Name: \n");
    char name[50];
    scanf("%s", &name);
    printf("Your name is : \n%s\n", name);
    fflush(stdin); //clears the input buffer
    //scanf puts a newline after we put a space which otherwise would result in an unexpected behaivior
    //meaning gets() won't take a new input 
    //instead takes the remaining input of scanf after the space
    printf("Enter Your Name: \n");
    char name2[25];
    gets(name2);
    printf("Your name is : \n%s\n", name2);

    return 0;
}