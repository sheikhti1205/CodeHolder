#include <stdio.h>
int main() {
    //cotinue = skips rest of code & forces the next iteration of the loop
    //break = exits a loop/switch

    for(int i = 1; i <= 20; i++) {
        if(i == 13) {
            //continue;  //cotinue = skips rest of code & forces the next iteration of the loop
            //break;     //break = exits a loop/switch
        }
        printf("%d\n", i);
    }
}