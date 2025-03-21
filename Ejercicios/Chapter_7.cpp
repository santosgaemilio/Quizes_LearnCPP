#include "Chapter_7.h"
#include "../Chapter_7_Aux/constants.h"
#include <iostream>
static int accumulate(const int x) {
    static int sum {0};
    return sum += x;
}
namespace Chapter7 {
    void howBigIsTheClass()
    {
        std::cout << "How many students are in your class? ";
        int students{};
        std::cin >> students;
        if (students > Constants::maxClassSize)
            std::cout << "There are too many students in this class";
        else
            std::cout << "This class isn't too large";
    }
    void printAccumulatedNumbers() {
        std::cout << accumulate(4) << '\n';
        std::cout << accumulate(3) << '\n';
        std::cout << accumulate(2) << '\n';
        std::cout << accumulate(1) << '\n';
    }
}
