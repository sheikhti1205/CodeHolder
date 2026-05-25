#include <stdio.h>

void hello(char[], int); //function prototype

int main() {
    //Function Prototype
    //What is it?
    //Function declaration, w/o a body, before main()
    //Ensures that calls to a function are made with the correct arguments

    /* IMPORTANT NOTES
    Many C compilers do not check for parametere matching
    Missing arguments will result in unexpected behaivior
    A ""FUNCTION PROTOTYPE"" cause the compiler to flag an error if arguments are missing*/

    /*ADVANTAGES
    1. Easier to navigate a program w/o main() at the top
    2. Helps with Debugging
    3. Commonly used in header files*/

    char name[] = "Bro";
    int age = 20;

    hello(name, age);

    return 0;
}

void hello(char name[], int age) {
    printf("\nHello %s", name);
    printf("\nYou are %d years old", age);
}