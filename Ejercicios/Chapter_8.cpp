#include "Chapter_8.h"
#include <iostream>
#include <limits>
#include <cassert>
#include "Random.h"
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

// Question 2 --------------------------------------------------------------------
static bool isPrime(const int number) {
    if (number < 2) return false;
    if (number > 2 && number % 2 == 0) return false;
    /*
     * Checa la parte de el comparador
     * se ponde así por que solo tienes
     * que checar hasta el squrt(number).
     * Pero como es una igualdar, se pueden
     * calcular el cuadrado de los dos lados.
     */
    for (int i = 3; i * i <= number; i+=2) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}
// -------------------------------------------------------------------------------
// Question 3 --------------------------------------------------------------------
static char getAnAnswer(const std::string_view message){
    std::cout << message << '\t' << std::endl;
    char answer {};
    while (!(std::cin >> answer) && (answer != 'y' || answer != 'n')) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << message << '\t' << std::endl;
    }
    return answer;
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
    void primeNumbersTest() {
        assert(!isPrime(0)); // terminate program if isPrime(0) is true
        assert(!isPrime(1));
        assert(isPrime(2));  // terminate program if isPrime(2) is false
        assert(isPrime(3));
        assert(!isPrime(4));
        assert(isPrime(5));
        assert(isPrime(7));
        assert(!isPrime(9));
        assert(isPrime(11));
        assert(isPrime(13));
        assert(!isPrime(15));
        assert(!isPrime(16));
        assert(isPrime(17));
        assert(isPrime(19));
        assert(isPrime(97));
        assert(!isPrime(99));
        assert(isPrime(13417));

        std::cout << "Success!\n";
    }
    void hiLoGame() {
        bool continueGame {true};
        while (continueGame) {
            const int numberToGuess {Random::get(1, 100)};
            std::cout <<
            "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is."
                    << std::endl;
            for (int i = 1; i <= 7; ++i) {
                const int guess {static_cast<int>(enterADoubleNumber("Guess #" + std::to_string(i) + ":"))};
                if (guess == numberToGuess) {
                    std::cout << "Correct! You win!" << std::endl;
                    break;
                }
                if (guess > numberToGuess) {
                    std::cout << "Your guess is too high!" << std::endl;
                } else {
                    std::cout << "Your guess is too low!" << std::endl;
                }
                if (i == 7) {
                    std::cout << "You lose, fuck you!" << std::endl;
                }
            }
            const char answer {getAnAnswer("Would you like to play again (y/n)?")};
            continueGame = answer == 'y';
        }
        std::cout << "Thank you for playing." << std::endl;
    }
}