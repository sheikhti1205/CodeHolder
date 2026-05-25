#include <stdio.h>

enum day{Sun =1, Mon =2, Tue =3, Wed =4, Thu =5, Fri =6, Sat =7};

int main() {
    /*
    ENUM = a user defined type of named integer identifiers
             helps to make a programme more readable
    */

   enum day today = Sat;  //ENUM's aren't STRINGS, but they can be treated as integer

   //printf("%d", today);

   if(today == Sun || today == Sat) {
    printf("\nIt's the weekend! Party time!");
   }
   else{
    printf("\nI have to work today!");
   }

    return 0;
}