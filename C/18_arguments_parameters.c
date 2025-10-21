#include <stdio.h>

void birthday(char name [], int age) {
    printf("\nHappy Birthday Dear %s!", name);
    printf("\nHappy Birthday To You!");
    printf("\nNow You Are %d Years Old", age);
}

int main () {

    char name[] = "Bro";
    int age = 20;

       birthday(name, age);
       birthday(name, age);
       birthday(name, age);

    return 0;
}