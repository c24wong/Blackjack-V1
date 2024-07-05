#include <iostream>
#include <vector>
#include <string>

#include "card.h"
#include "deck.h"

using namespace std;

int main(){
    Deck deck;
    deck.initializeDeck();
    
//    Test case
//    cout << "Deck created:" << endl;
//    deck.printDeck();

    deck.shuffle();

    cout << "Deck shuffled:" << endl;
    deck.printDeck();

    return 0;
}