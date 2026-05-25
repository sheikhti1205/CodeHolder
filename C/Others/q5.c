#include <stdio.h>
#include <string.h>
#include <ctype.h>

int pass(char *str){

    int hasupper = 0, haslower = 0, hasdigit = 0, hasspecial = 0;

    const char *specials = "(,.;:<>)";

    if(strlen(str) < 12){
        return -1;
    }
    for(int i = 0; i < strlen(str); i++){
        if(isupper(str[i])) hasupper = 1;
        if(islower(str[i])) haslower = 1;
        if(isdigit(str[i])) hasdigit = 1;
        if(strchr(specials, str[i])) hasspecial = 1;
    }

    if(hasdigit == 1 && haslower == 1 && hasspecial == 1 && hasupper == 1){
        return 1;
    }

    return -1;
};

int main(){
    printf("Enter your password: \n");
    char str[1000];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    if(pass(str) == 1){
        printf("Strong Password\n");
    }else{
        printf("Weak Password\n");
    }

    return 0;
}