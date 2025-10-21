#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validate(char *sms){
    char cu[3], hscboard[4], sscboard[4];
    int hscroll, hscyear, sscroll, sscyear;

    if(sscanf(sms, "%s %3s %d %d %3s %d %d", cu, hscboard, &hscroll, &hscyear, sscboard, &sscroll, &sscyear) != 7){
        return 0;
    }
    if(strcmp(cu, "CU") != 0){
        return 0;
    }
    for(int i = 0; i < 3; i++){
        if((!isupper(hscboard[i])) || (!isupper(sscboard[i]))){
            return 0;
        }
    }
    if((hscboard[3] != '\0') || (sscboard[3] != '\0')){
        return 0;
    }
    if(hscyear < sscyear + 2){
        return 0;
    }

    return 1;
};

int main(){
    char sms[100];
    printf("Enter your string: \n");
    
    fgets(sms, sizeof(sms), stdin);
    sms[strcspn(sms, "\n")] = '\0';

    if(validate(sms)){
        printf("VALID\n");
    }else{
        printf("INVALID\n");
    }
}