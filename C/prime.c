#include <math.h>
#include <stdio.h>

int prime_check(int num) {
  if (num <= 1) {
    return 0;
  }
  int sqrt_num = (int)sqrt(num);

  for (int i = 2; i <= sqrt_num; i++) {
    if (num % i == 0) {
      return 0;
      break;
    }
  }
  return 1;
}

int main() {
  int num;
  printf("Enter any number: \n");
  scanf("%d", &num);

  int result = prime_check(num);

  if (result == 1) {
    printf("The Entered number is a prime number\n");
  }
  if (result == 0) {
    printf("The entered number isn't a prime number\n");
  }

  return 0;
}
