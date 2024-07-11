#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <array>

#include "game.h"

using namespace std;

Game::Game() : currentBet(0), resetToken(false){
    deck.shuffle();
}

void Game::setMoney(int money){
    playerMoney = money;
}

void Game::gameStart(){
    while (true) {
        if(resetToken){
            int newMoney;
            cout << "You are out of money! Deposit new amount or quit " << endl;
            cout << "1. Deposit" << endl;
            cout << "2. Quit" << endl;
            int answer;
            cin >> answer;
                if(answer == 1){
                    cin >> newMoney;
                    setMoney(newMoney);
                resetToken = false;
                }
                else{
                    exit(0);
            }
        }
    }

    while(playerMoney != 0){
        placeBet();
        dealHand();
        playerTurn();
        dealerTurn();
        decideWin();
        resetRound();
    }
}

void Game::placeBet(){
    cout << "You have $" << playerMoney << ". Enter your bet: ";
    cin >> currentBet;
    while (currentBet > playerMoney || currentBet <= 0) {
        cout << "Invalid bet amount. Please enter a valid bet: ";
        cin >> currentBet;
    }
    playerMoney -= currentBet;
}

//void Game::dealHand(){}
//void Game::playerTurn(){}
//void Game::dealerTurn(){}
//void Game::decideWin(){}
//void Game::resetRound(){}
