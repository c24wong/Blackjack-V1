#include <iostream>
#include <vector>
#include <string>

#include "card.h"
#include "deck.h"
#include "game.h"

using namespace std;

int main(){
    Game game;

    int initialMoney;
    cout << "Enter deposit amount: ";
    cin >> initialMoney;
    game.setMoney(initialMoney);

    game.gameStart();

    return 0;
}