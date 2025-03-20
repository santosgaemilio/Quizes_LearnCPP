#include "Chapter_1.h"
#include <iostream>

namespace Chapter1 {
    void addAndSubstract() {
        int num1 {};
        int num2 {};
        std::cout << "Enter an integer:\t";
        std::cin >> num1;
        std::cout << "Enter another integer:\t";
        std::cin >> num2;
        std::cout << num1 << " + " << num2 << " is " << num1 + num2 << '.' << std::endl;
        std::cout << num1 << " - " << num2 << " is " << num1 - num2 << '.' << std::endl;
    }
}
