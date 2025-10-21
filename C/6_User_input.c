#include <stdio.h>
#include <string.h>
int main () {
    char name[30];
    int age;
    int year;
    float gpa;
    char grade[2];

    printf("Your name is?\n");
    //scanf("%s", &name);
    fgets(name, sizeof(name), stdin);
    name[strlen(name)-1] = '\0';
    printf("Your age?\n");
    scanf("%d", &age);
    printf("Year of passing\n");
    scanf("%d", &year);
    printf("Your GPA is?\n");
    scanf("%f", &gpa);
    printf("Your Avg. Grade is?\n");
    scanf("%s", &grade);
    printf("Hello %s\n", name);
    printf("You are %d years old\n", age);
    printf("You passed SSC in %d\n", year);
    printf("Your GPA is %f\n", gpa);
    printf("Your Avg. Grade is %s", grade);

    return 0;
}