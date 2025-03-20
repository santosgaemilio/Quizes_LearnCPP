#include "Chapter_2.h"

#include <iostream>

static int readNumber() {
    std::cout << "Enter a number: ";
    int num {};
    std::cin >> num;
    return num;
}
static void writeAnswer(const int answer) {
    std::cout << "Answer: " << answer << std::endl;
}
namespace Chapter2 {
    void pseudoMain() {
        const int firstNumber { readNumber() };
        const int secondNumber { readNumber() };
        writeAnswer(firstNumber + secondNumber);
    }
}
