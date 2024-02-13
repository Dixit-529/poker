#include <iostream>
#include <fstream>
#include "card.h"
#include "hand.h"

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        Hand blackHand(line.substr(0, 14));
        Hand whiteHand(line.substr(15));
        int result = blackHand.compare(whiteHand);
        if (result > 0) {
            std::cout << "Black wins." << std::endl;
        } else if (result < 0) {
            std::cout << "White wins." << std::endl;
        } else {
            std::cout << "Tie." << std::endl;
        }
    }

    return 0;
}

