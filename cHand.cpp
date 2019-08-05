/*
=================
cHand.cpp
- Header file for class definition - IMPLEMENTATION
=================
*/
#include "cHand.h"
/*
=================
- Data constructor initializes the Hand 
- Is always called, thus ensures all card objects are in a consistent state.
=================
*/

cHand::cHand()   // Constructor - will create an instance of the card class.
{
	cHand::handSize = 0;
	cHand::aHand.reserve(7);     // defines an array a temporary array of cards
}
/*
=================
- adds a card to the hand.
=================
*/

void cHand::addCard(cCard* aCard)        // Adds a card to the current hand.
{
	cHand::handSize++; // Increments the hand size
	cHand::aHand.push_back(aCard);
}
/*
=================
- Clear all the cards from the hand.
=================
*/
void cHand::clearHand()     // Clear all the cards from the hand.
{
	cHand::handSize = 0; // Resets the hand size

	// This method will iterate through the vector (aHand)
	// removing the cards by freeing all the memory on the heap
	std::vector<cCard*>::iterator iter = aHand.begin();
	for (iter = cHand::aHand.begin(); iter != cHand::aHand.end(); ++iter)
	{
		delete *iter;
		*iter = 0;
	}
	// Clear vector of pointers
	cHand::aHand.clear();
}

/*
=================
- Displays on screen the current Card details for the Card instance.
=================
*/
short cHand::gethandValue()       // Get a card from the top of the pack
{
	// If the Hand is empty, contains no cards return a value of zero (0)
	if (cHand::aHand.empty())
		return 0;

	// iterate through aHand to adding up the card values
	// fro the moment treate ACES as having a value of 1
	short total = 0;
	std::vector<cCard*>::const_iterator iter;
	bool containsAce = false;

	for ( iter = cHand::aHand.begin(); iter != cHand::aHand.end(); ++iter)
	{
		total += (*iter)->getCardValue();
		if ((*iter)->getCardValue() == (int)EType::ace)
		{
			containsAce = true;
		}
	}

	// If the hand contains an ace and the total is 11 or less treat ace as high
	if (containsAce && total <= 11)
	{
		// Add 10 as ACE value of 1 already counted
		total += 10;
	}
	
	return total;
}

/*
=================
- Returns the current size of the hand based on the number of cards held
=================
*/
short cHand::getHandSize() {
	return (cHand::handSize);
}

/*
=================
- Displays all the cards in the current hand.
=================
*/

void cHand::showHand() 		// Display cards in hand;
{
	// This method will iterate through the vector (aHand)
	// displaying the cards in the hand
	std::vector<cCard*>::iterator iter = aHand.begin();
	for (iter = cHand::aHand.begin(); iter != cHand::aHand.end(); ++iter)
	{
		(*iter)->showCard();
	}

}
/*
=================
- Flip the first card in the hand to face down.
=================
*/

void cHand::flipCard() 		// flip card face up down.
{
	cHand::aHand.front()->setFaceUp();
}

/*
=================
- Determine if the hand is empty
=================
*/
bool cHand::handIsEmpty() 			// Determine if there are any cards in the  hand
{
	return cHand::aHand.empty();
}