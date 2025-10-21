#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int>prime;
    for(int i=2; i<=100000; i++){
        bool isPrime = true;
        for(int j=2; j*j <= i; j++){
            if(i % j == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime){
            prime.push_back(i);
        }
    }
}