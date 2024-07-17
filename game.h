#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <array>

#include "card.h"
#include "deck.h"

using namespace std;

class Game{
    public:
        Game();
        void setMoney(int money);
        void gameStart();
        void printHand(const vector<Card>& hand) const;
        void dealHand();
        void playerTurn();
        void dealerTurn();
        void decideWin();
        void placeBet();
        void resetRound();

    private:
        Deck deck;

        vector<Card> playerHand;
        vector<Card> dealerHand;

        int playerMoney;
        int currentBet;
        bool resetToken;
};

#endif