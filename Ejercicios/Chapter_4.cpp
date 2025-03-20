#include "Chapter_4.h"

#include <iostream>
#include <limits>
// Internal by default (constexp)
constexpr double gravity {9.8};

// QUESTION 2 --------------------------------------------------------------------
static double enterADoubleNumber(const std::string_view message) {
    std::cout << message << '\t' << std::endl;
    double number {};
    while (!(std::cin >> number)) {
        std::cin.clear();
        /**
         *  El numeric_limits te da los limites de lo que pongas
         *  entre los <>, en esta caso el streamsize del std, y
         *  de ahí sacamos el máximo para que sepa que se tiene que
         *  saltar todo hasta el \n
         */
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << message << '\t' << std::endl;
    }
    return number;
}
static char enterAnAritmethicSymbol() {
    std::cout << "Enter the operation to perform [+,-,*,/]: ";
    char operation {};
    std::cin >> operation;
    return operation;
}
static bool isSymbolCorrect(const char symbol) {
    switch (symbol) {
    case '+':
    case '-':
    case '*':
    case '/':
        return true;
    default:
        return false;
    }
}
static void makeOperation(const double n1, const double n2, const char symbol) {
    switch (symbol) {
    case '+':
        std::cout << n1 << " + " << n2 << " is " << n1 + n2;
        break;
    case '-':
        std::cout << n1 << " - " << n2 << " is " << n1 - n2;
        break;
    case '*':
        std::cout << n1 << " * " << n2 << " is " << n1 * n2;
        break;
    case '/':
        std::cout << n1 << " / " << n2 << " is " << n1 / n2;
        break;
    default:
        break;
    }
}
// -------------------------------------------------------------------------------
static double getDistanceFallen(const int secondsPassed) {
    return gravity * (secondsPassed * secondsPassed) / 2;
}
static double getBallHeight(const double towerHeight, const int secondsPassed) {
    const double height {towerHeight - getDistanceFallen(secondsPassed)};
    return height < 0 ? 0 : height;
}
static void printBallPosition(const int secondsPassed, const double height) {
    std::cout << "At " << secondsPassed <<
                " seconds, " << " the ball is at height: " <<
                height << " meters" << std::endl;
}
// QUESTION 3 --------------------------------------------------------------------
namespace Chapter4 {
    void operateOnTwoDoubles() {
        const double firstNumber {enterADoubleNumber("Enter the first number:")};
        const double secondNumber {enterADoubleNumber("Enter the second number:")};
        char operation {};
        do {
            operation = enterAnAritmethicSymbol();
        } while (!isSymbolCorrect(operation));
        makeOperation(firstNumber, secondNumber, operation);
    }
    void calculateTheFallOfABall() {
        const double towerHeight {enterADoubleNumber("Enter the height of the tower:")};
        for (int i = 0; i <= 5; ++i) {
            printBallPosition(
                i,
                getBallHeight(towerHeight, i)
            );
        }
    }
}
