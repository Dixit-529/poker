#include "hand.h"
#include <algorithm>
#include <map>


Hand::Hand(const std::string& handString) {
    for (size_t i = 0; i < handString.size(); i += 3) {
        cards.push_back(Card(handString[i], handString[i + 1]));
    }
}

// Helper function to check if a hand is a straight
bool isStraight(const std::vector<Card>& cards) {
    std::vector<int> values;
    for (const auto& card : cards) {
        values.push_back(card.getValueRank());
    }
    std::sort(values.begin(), values.end());
    for (size_t i = 1; i < values.size(); ++i) {
        if (values[i] != values[i - 1] + 1) {
            return false;
        }
    }
    return true;
}

// Helper function to check if a hand is a flush
bool isFlush(const std::vector<Card>& cards) {
    char suit = cards[0].getSuit();
    for (const auto& card : cards) {
        if (card.getSuit() != suit) {
            return false;
        }
    }
    return true;
}

std::vector<Card> Hand::getCards() const {
    return cards;
}

// Helper function to count occurrences of each card value
std::map<char, int> countCardValues(const std::vector<Card>& cards) {
    std::map<char, int> counts;
    for (const auto& card : cards) {
        counts[card.getValue()]++;
    }
    return counts;
}

int Hand::getRank() const {
    std::vector<Card> sortedCards = cards;
    std::sort(sortedCards.begin(), sortedCards.end(), [](const Card& a, const Card& b) {
        return a.getValueRank() < b.getValueRank();
    });

    bool straight = isStraight(sortedCards);
    bool flush = isFlush(cards);
    auto valueCounts = countCardValues(cards);

    if (straight && flush) {
        return 9; // Straight Flush
    }
    if (valueCounts.size() == 2) {
        for (const auto& pair : valueCounts) {
            if (pair.second == 4) {
                return 8; // Four of a Kind
            } else if (pair.second == 3) {
                return 7; // Full House
            }
        }
    }
    if (flush) {
        return 6; // Flush
    }
    if (straight) {
        return 5; // Straight
    }
    if (valueCounts.size() == 3) {
        return 4; // Three of a Kind
    }
    if (valueCounts.size() == 4) {
        return 3; // Two Pairs
    }
    if (valueCounts.size() == 5) {
        return 2; // Pair
    }
    return 1; // High Card
}

int Hand::compare(const Hand& other) const {
    int rankThis = getRank();
    int rankOther = other.getRank();
    if (rankThis != rankOther) {
        return rankThis - rankOther;
    }

    std::vector<Card> sortedThis = cards;
    std::sort(sortedThis.begin(), sortedThis.end(), [](const Card& a, const Card& b) {
        return a.getValueRank() > b.getValueRank();
    });
    std::vector<Card> sortedOther = other.getCards();
    std::sort(sortedOther.begin(), sortedOther.end(), [](const Card& a, const Card& b) {
        return a.getValueRank() > b.getValueRank();
    });

    for (size_t i = 0; i < sortedThis.size(); ++i) {
        if (sortedThis[i].getValueRank() != sortedOther[i].getValueRank()) {
            return sortedThis[i].getValueRank() - sortedOther[i].getValueRank();
        }
    }

    return 0; // Tie
}

