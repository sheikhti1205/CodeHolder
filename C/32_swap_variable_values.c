#include <stdio.h>
#include <string.h>
int main() {
/*
    char x ='X';
    char y = 'Y';
    char temp;
    temp = x;
    x=y;
    y = temp;
    //y = x;
    printf("\nx = %c\n", x);
    printf("\ny = %c\n", y);
*/
   char x[25] = "Lemonade";
   char y[25] = "Water"; //if second string is smaller than the first string there may be issues
   char temp[25];         //to solve the issue just add a sufficiently large enough size in []

   strcpy(temp, x); //copies x to temp
   strcpy(x, y); //copies y to x
   strcpy(y, temp); //copies temp to y

   printf("\nx = %s\n", x);
   printf("\ny = %s\n", y);

}