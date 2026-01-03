#include <iostream>

int main() {
    int number = 123;
    int remainder = number / 10;
    std::cout << "The number is: " << number << std::endl;
    std::cout << "The last digit (number % 10) is: " << remainder << std::endl;
    return 0;
}
