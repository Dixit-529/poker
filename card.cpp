#include "card.h"

Card::Card(char value, char suit) : value(value), suit(suit) {}

char Card::getValue() const {
    return value;
}

char Card::getSuit() const {
    return suit;
}

int Card::getValueRank() const {
    const char* values = "23456789TJQKA";
    for (int i = 0; values[i]; ++i) {
        if (values[i] == value) {
            return i;
        }
    }
    return -1;
}

