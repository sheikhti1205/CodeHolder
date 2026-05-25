#include <stdio.h>

int main(){
    int id = 220042112;
    
    int batch = id / 10000000;

    int dept = (id / 10000) % 100;

    int section = (id / 100) % 10;

    switch(dept){
        case 1 : printf("MPE\n"); break;
        case 4 : printf("CESI\n"); break;
        default : printf("Unknown\n");
    }

    return 0;
}