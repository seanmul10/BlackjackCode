/*
=================
cPlayer.h
- Header file for class definition - SPECIFICATION
- Header file for the Player class
=================
*/
#ifndef _CPLAYER_H
#define _CPLAYER_H
#include "cHand.h"

class cPlayer
{
private:
	std::string playerName;
	cHand playerHand;

public:
	cPlayer(const std::string& name);   // Constructor - will create an instance of the cPlayer class.
	bool pIsBust();     // Returns whether the players hand is over 21 therefore "bust".
	bool pHasNatural();		// Returns true if the player has 21 after being dealt only 2 cards.
	void msgPlayerBust();    // Displays that the player has bust.
	std::string getPlayerName(); // Return the name of the player
	short getPlayerHandSize(); // Gets the size of the players hand.
	short getPlayerHandValue();  // Return the total value of the players hand
	void setPlayerHand(cCard* aCard); // add a card to the players hand
	void showPlayerHand();		// Displays the cards in the players hand
	bool playerHandIsEmpty();			// Determine if there are any cards in the players hand
	void flipFirstCard();        // Flip the first card
	void msgPlayerWins();		// Displays that the player has won.
	void clearHand();		// Clears the players hand.
};
#endif