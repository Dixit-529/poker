#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
private:
    char value;
    char suit;

public:
    Card(char value, char suit);
    char getValue() const;
    char getSuit() const;
    int getValueRank() const;
};

#endif // CARD_H

