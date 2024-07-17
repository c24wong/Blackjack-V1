#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <array>

#include "deck.h"

using namespace std;

Deck::Deck() : currentCardIndex(0) {
    initializeDeck();
}

void Deck::initializeDeck(){
    string numbers[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    int position = 0;

    for(const auto& suit : suits){
        for(const auto& number : numbers){
            deck[position++] = {number, suit};
        }
    }
}

void Deck::printDeck() const {
    for (const auto& card : deck) {
       cout << card.number << " of " << card.suit << endl;
    }
}

void Deck::shuffle() {
    srand(static_cast<unsigned>(std::time(0)));
    random_shuffle(deck.begin(), deck.end());
    currentCardIndex = 0;
}

//void getHand()

int Deck::cardValue(const Card& card) const{
    int value = 0;
    if (card.number == "J" || card.number == "Q" || card.number == "K"){
       value += 10;
    }
    else if (card.number == "A"){
        value += 11;
    }
    else{
       value += stoi(card.number);
    }
    return value;
}

Card Deck::drawCard() {
    if (currentCardIndex >= deckSize) {
        shuffle(); // Shuffle if we've used all the cards
    }
    return deck[currentCardIndex++];
}

//Card Deck::getCard(int index) const {
//    if (index >= 0 && index < deckSize) {
//        return deck[index];
//   } else {
//        throw out_of_range("Index out of range");
//    }
//}
