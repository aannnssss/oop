#include <iostream>
#include "turkish.hpp"

int main() {

    int n;

    std::cin >> n;
    std::cout << translationIntoTurkish(n) << std::endl;

    return 0;
}