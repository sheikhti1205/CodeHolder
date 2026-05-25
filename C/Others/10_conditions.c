#include <stdio.h>
#include <math.h>
int main () {
    int age;
    int rem;
    int rem2;
    int rem3;
    int A = 12;
    int B = 365;
  

        printf("\nEnter your age\n");
        scanf("%d", &age);
        rem = 18 - age;
        rem2 = rem*A;
        rem3 = rem*B;

        if(age > 18 && age <100) {
    printf("\nYou are old enough!");   
    }
        else if(age == 18) {
    printf("\nCongrats you barely made it!");
    }
        else if(age <0) {
    printf("Stop joking around!\nTry again!\n");
    }
        else if(age <18) {
    printf("\nDon't continue further!\nCome back after,\n%d years!", rem);
    printf("\nOr \n%d months", rem2);
    printf("\nOr \n%d days", rem3);
        }
        else if(age >=100) {
    printf("...");
        }
    

    return 0;
}