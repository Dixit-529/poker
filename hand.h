#ifndef HAND_H
#define HAND_H

#include <vector>
#include <string>
#include "card.h"

class Hand {
private:
    std::vector<Card> cards;

public:
    Hand(const std::string& handString);
    std::vector<Card> getCards() const;
    int getRank() const;
    int compare(const Hand& other) const;
};

#endif
