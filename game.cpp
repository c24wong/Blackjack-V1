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
                    cout << "Enter deposit amount: ";
                    cin >> newMoney;
                    setMoney(newMoney);
                resetToken = false;
                }
                else{
                    exit(0);
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

    if(playerMoney == 0){
        resetToken = true;
    }
    }
}

void Game::printHand(const vector<Card>& hand) const {
    for (size_t i = 0; i < hand.size(); ++i) {
        cout << hand[i].number << " of " << hand[i].suit;
        if (i < hand.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

void Game::placeBet(){
    cout << "You have $" << playerMoney << ". Enter your bet (or enter 0 to quit): ";
    cin >> currentBet;
    if (currentBet == 0) {
        cout << "Game quitting. Goodbye!" << endl;
        exit(0);
    }
    while (currentBet > playerMoney || currentBet <= 0) {
        cout << "Invalid bet amount. Enter a valid bet (or enter 0 to quit): ";
        cin >> currentBet;
        if (currentBet == 0) {
            cout << "Game quitting. Goodbye!" << endl;
            exit(0);
        }
    playerMoney -= currentBet;
    }
}

void Game::dealHand(){
    playerHand.push_back(deck.drawCard());
    dealerHand.push_back(deck.drawCard());
    playerHand.push_back(deck.drawCard());
    dealerHand.push_back(deck.drawCard());

    cout << "Your hand: ";
    printHand(playerHand);
    cout << "Dealer's hand: ";
    cout << dealerHand[0].number << " of " << dealerHand[0].suit << " and [hidden card]" << endl;
}

int Game::calculateHandValue(const vector<Card>& hand) const {
    int totalValue = 0;
    int aceCount = 0;

    for (const auto& card : hand) {
        if (card.number == "J" || card.number == "Q" || card.number == "K") {
            totalValue += 10;
        } else if (card.number == "A") {
            totalValue += 11;
            aceCount++;
        } else {
            totalValue += stoi(card.number);
        }
    }
    while (totalValue > 21 && aceCount > 0) {
        totalValue -= 10;
        aceCount--;
    }
    return totalValue;
}

void Game::playerTurn(){
    string choice;
    while (calculateHandValue(playerHand) < 21) {
        cout << "Hit or Stand? (h or s): ";
        cin >> choice;
        if(choice == "h" || choice == "hit" || choice == "Hit"){
             playerHand.push_back(deck.drawCard());
             cout << "Your hand: ";
             printHand(playerHand);
        }
        else{
            break;
        }
    }
}

void Game::dealerTurn() {
    while (calculateHandValue(dealerHand) < 17) {
        dealerHand.push_back(deck.drawCard());
    }
    cout << "Dealer's hand: ";
    printHand(dealerHand);
}

void Game::decideWin(){
    int playerValue = calculateHandValue(playerHand);
    int dealerValue = calculateHandValue(dealerHand);

    if (playerValue > 21){
        cout << "You busted! Dealer Wins." << endl;
    }
    else if (dealerValue > 21){
        cout << "Dealer busted! You win!" << endl;
        playerMoney += currentBet * 2;
    }
    else if (playerValue > dealerValue){
        cout << "You win!" << endl;
        playerMoney += currentBet * 2;
    }
    else if (playerValue < dealerValue){
        cout << "Dealer wins" << endl;
    }
    else{
        cout << "Tie!" << endl;
        playerMoney += currentBet;
    }

    if (playerMoney <= 0){
        resetToken = true;
    }
}

void Game::resetRound() {
    playerHand.clear();
    dealerHand.clear();
    if (playerMoney <= 0) {
        resetToken = true;
    }
}
