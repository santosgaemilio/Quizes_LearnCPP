#include "Chapter_5.h"

#include <iostream>
#include <string>
static std::string getName(const int personNumber) {
    std::cout << "Enter the name of person " << '#' << personNumber << ": " << std::endl;
    std::string name {};
    std::getline(std::cin >> std::ws, name);
    return name;
}
static int getAge(const int personNumber) {
    std::cout << "Enter the age of person " << '#' << personNumber << ": " << std::endl;
    int age {};

    while (!(std::cin >> age)) {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Enter the age of person " << '#' << personNumber << ": " << std::endl;
    }
    return age;
}
namespace Chapter5 {
    void checkWhosOlder() {
        const std::string firstPersonName {getName(1)};
        const int firstPersonAge {getAge(1)};
        const std::string secondPersonName {getName(2)};
        const int secondPersonAge {getAge(2)};
        if (firstPersonAge > secondPersonAge) {
            std::cout << firstPersonName
                        << "(age " << firstPersonAge << ") is older than "
                        << secondPersonName << "(age " << secondPersonAge << ")" << std::endl;
        } else {
            std::cout << secondPersonName
                        << "(age " << secondPersonAge << ") is older than "
                        << firstPersonName << "(age " << firstPersonAge << ")" << std::endl;
        }
    }
}