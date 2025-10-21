#include <stdio.h>
#include <stdbool.h>
int main () {
    //logical operator = ! (NOT) reverse the state of a condition
  
    bool sun = 0; //(true = 1 false = 0)

    if(!sun){
        printf("\nIt's cloudy outside");
    }
    else{
        printf("\nIt's sunny outside");
    }

    return 0;
}