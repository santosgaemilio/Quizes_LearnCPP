#include "Chapter_6.h"
#include <iostream>
#include <string>

// Write the function getQuantityPhrase() here
static std::string getQuantityPhrase(const int quantity) {
    switch (quantity) {
        case 0:
            return "no";
        case 1:
            return "a single";
        case 2:
            return "a couple of";
        case 3:
            return "a few";
        default: {
            if (quantity < 0) {
                return "negative";
            }
            if (quantity > 3) {
                return "many";
            }
            return "many";
        }
    }
}
// Write the function getApplesPluralized() here
static std::string getApplesPluralized(const int quantity) {
    return quantity == 1 ? "apple" : "apples";
}

namespace Chapter6 {
    void appleOdyssey()
    {
        constexpr int maryApples { 3 };
        std::cout << "Mary has " << getQuantityPhrase(maryApples) << ' ' << getApplesPluralized(maryApples) << ".\n";

        std::cout << "How many apples do you have? ";
        int numApples{};
        std::cin >> numApples;

        std::cout << "You have " << getQuantityPhrase(numApples) << ' ' << getApplesPluralized(numApples) << ".\n";
    }
}