#include <stdio.h>
#include <math.h>

int isPrime(int num){
    if(num < 2) return 0;
    
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0) return 0;
    }
    return 1;
};

int isSemiPrime(int num){
    for(int i = 2; i <= num/2; i++){
        if(num % i == 0 && isPrime(i) && (isPrime(num / i))){
            return 1;
        }
    }
    return 0;
};

int main(){
    printf("Enter a number: ");
    int num; scanf("%d", &num);

    if(isSemiPrime(num)){
        printf("%d is a semi prime number\n", num);
    }else{
        printf("%d is not a semi prime number\n", num);
    }

    return 0;
}