#include <stdio.h>

int print();

int main()
{
    int i = 0;
    /*while(i<5)
    {
        print();
        i++;
    } */
    sum();
}

//To call a function(eg. sum) in another function(eg. print) we must declare 
//it before the function(here- print) we want to call

int sum();

int print()
{
    printf("Hello\n");
    sum();
}

int sum()
{
    int a = 5, b = 4;
    printf("Sum = %d\n", a+b);
}

