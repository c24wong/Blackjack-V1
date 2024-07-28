# **Blackjack-V1**

This is a simple console-based Blackjack game written in C++. The game allows a player to place bets, draw cards, and try to beat the dealer by getting as close to 21 without going over.

**Features**
- Deck of Cards: The deck is initialized and shuffled before the game starts.
- Player Actions: The player can choose to hit or stand during their turn.
- Dealer Actions: The dealer will draw cards until their hand value is at least 17.
- Betting System: The player can place bets and the game will track the player's money.
- Game Restart: If the player runs out of money, they can choose to deposit more money or quit the game.

**Requirements**
- C++ compiler (e.g., g++)

**Files**
- main.cpp: Entry point of the game.
- game.h and game.cpp: Contains the Game class which handles the game logic.
- deck.h and deck.cpp: Contains the Deck class which handles deck operations.
- card.h: Defines the Card struct.