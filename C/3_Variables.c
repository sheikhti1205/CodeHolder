#include <stdio.h>
int main () {

    int x; //declaration
    x = 12; //initialization

    int y = 16; //declaration & initialization

    int age = 16; //integer
    float gpa = 5.00; //floating point number
    char grade = 'A'; //single character
    char name[] = "Sheikh Nayeem Uddin"; // array of characters
    const float PI = 3.14; //const make things unchangeable

    printf("X is equal to %d\n", x);
    printf("Y is equal to %d\n", y);

    printf("Hello, %s\n", name);
    printf("You are %d years old\n", age);
    printf("You got %c in SSC\n", grade);
    printf("Your GPA is %.1f\n", gpa);
    
    //can't put a different value for PI like, PI = 12

    return 0;
}