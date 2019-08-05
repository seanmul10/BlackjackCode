/*
=================
cHand.h
- Header file for class definition - SPECIFICATION
- Header file for the Hand class
=================
*/
#ifndef _CHAND_H
#define _CHAND_H
#include "cCard.h"

class cHand
{
private:
	std::vector<cCard*> aHand;
	int handSize;		// Keeps track of the current hand size
	
public:
	cHand();              // Constructor - will create an instance of the card class.
	void addCard(cCard* aCard);      // Adds a card to the current hand.
	void clearHand();     // Clear all the cards from the hand.
	short gethandValue();    // Returns the value of the current hand.
	void showHand();		// Display cards in hand;
	void flipCard();		// flip card face up down.
	bool handIsEmpty();			// Determine if there are any cards in the hand
	int getNumberofCards();		// return the number of cards in the vector
	cCard* getCardFromHand(int pos);     // return a card from the hand
	short getHandSize();	// Returns the amount of drawn cards in the current hand.
};
#endif