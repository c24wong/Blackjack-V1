#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <array>

#include "card.h"

using namespace std;

//int deckAmount = 1;
const int deckSize = 52;

class Deck{
    public:
        Deck();
        void initializeDeck();
        void printDeck() const;
        void shuffle();
        int cardValue(const Card& card) const;
    //    Card getCard(int index) const;

    private:
        array<Card, deckSize> deck;
        int currentCardIndex;

        //void getHand();
};

#endif