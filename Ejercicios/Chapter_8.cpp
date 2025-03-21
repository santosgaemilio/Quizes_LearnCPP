#include "Chapter_8.h"
#include <iostream>
#include <limits>
// Question 1 --------------------------------------------------------------------
constexpr double gravity {9.8};

static double enterADoubleNumber(const std::string_view message) {
    std::cout << message << '\t' << std::endl;
    double number {};
    while (!(std::cin >> number)) {
        std::cin.clear();
        /**
         *  El numeric_limits te da los limites de lo que pongas
         *  entre los <>, en esta caso el streamsize del std, y
         *  de ahí sacamos el máximo para que sepa que se tiene que
         *  saltar t_odo hasta el \n
         */
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << message << '\t' << std::endl;
    }
    return number;
}
static double getDistanceFallen(const int secondsPassed) {
    return gravity * (secondsPassed * secondsPassed) / 2;
}
static double getBallHeight(const double towerHeight, const int secondsPassed) {
    const double height {towerHeight - getDistanceFallen(secondsPassed)};
    return height < 0 ? 0 : height;
}
static void printBallPosition(const int secondsPassed, const double height) {
    if (height > 0.0) {
        std::cout << "At " << secondsPassed <<
                " seconds, " << " the ball is at height: " <<
                height << " meters" << std::endl;
    } else {
        std::cout << "At " << secondsPassed << " seconds,  the ball is on the ground.\n";
    }
}
// -------------------------------------------------------------------------------

namespace Chapter8 {
    void CalculateFullBallFall() {
        int secondsPassed {0};
        const double towerHeight {enterADoubleNumber("Enter tower height in meters: ")};
        if (towerHeight <= 0.0) std::cout << "Ball won't fall" << std::endl;
        double ballHeight {towerHeight};
        while (ballHeight > 0) {
            ballHeight = getBallHeight(towerHeight, secondsPassed);
            printBallPosition(secondsPassed, ballHeight);
            ++secondsPassed;
        }
    }
}