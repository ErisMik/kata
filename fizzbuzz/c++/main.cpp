// Eric Mikulin, 15-10-2019
// Fizzbuzz

#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    int endValue = std::stoi(argv[1]);

    for(int i = 1; i <= endValue; ++i) {
        if(i % 3 == 0 && i % 5 == 0) {
            std::cout << "fizzbuzz";
        } else if(i % 5 == 0) {
            std::cout << "fizz";
        } else if(i % 5 == 0) {
            std::cout << "buzz";
        } else {
            std::cout << i;
        }
        std::cout << " ";
    }
    std::cout << std::endl;

    return 0;
}