#include <stdio.h>
#include <string.h>

//typedef char user[25];

typedef struct {
    char name[25];
    char pass[12];
    int id;
} User;

int main() {
    /*typedef = reserved keyword that gives an existing datatype a "nickname"*/

    User user1 = {"Bro", "password123", 12345678};
    User user2 = {"Bruh", "password321", 87654321};


    //user user1[25] = "Bro";

    printf("%s\n", user1.name);
    printf("%s\n", user1.pass);
    printf("%d\n", user1.id);
    printf("%s\n", user2.name);
    printf("%s\n", user2.pass);
    printf("%d\n", user2.id);

    return 0;
}