/*
=================
cHand.cpp
- Header file for class definition - IMPLEMENTATION
=================
*/
#include "cPlayer.h"
/*
=================
- Data constructor initializes the Hand 
- Is always called, thus ensures all player objects are in a consistent state.
=================
*/

cPlayer::cPlayer(const std::string& name)   // Constructor - will create an instance of the player class.
{
	cPlayer::playerName = name;     // associates a  name to the player object
}
/*
=================
- Check if player is bust.
=================
*/
bool cPlayer::pIsBust()     // Returns whether the players hand is over 21 therefore "bust".
{
	return (playerHand.gethandValue() > 21);
}

/*
================ =
-Check if player has a natural blackjack
================ =
*/
bool cPlayer::pHasNatural()     // Returns whether the players hand is over 21 therefore "bust".
{
	return (playerHand.gethandValue() == 21 && playerHand.getHandSize() == 2);
}

/*
=================
- Displays that the player has bust.
=================
*/
void cPlayer::msgPlayerBust()       // Displays that the player has bust.
{
	std::cout << cPlayer::playerName << " you're bust!\n";
}
/*
=================
- Returns the player name.
=================
*/
std::string cPlayer::getPlayerName() // Return the name of the player
{
	return cPlayer::playerName;
}
/*
=================
- Returns the players hand value.
=================
*/
short cPlayer::getPlayerHandValue()  // Return the total value of the players hand
{
	return cPlayer::playerHand.gethandValue();
}

/*
=================
- Returns the players hand size
=================
*/
short cPlayer::getPlayerHandSize()  // Return the total value of the players hand
{
	return cPlayer::playerHand.getHandSize();
}

/*
=================
- Adds a card to the players hand.
=================
*/
void cPlayer::setPlayerHand(cCard* aCard)  // add a card to the players hand
{
	cPlayer::playerHand.addCard(aCard);
}
/*
=================
- Diaplays the cards in the players hand
=================
*/
void cPlayer::showPlayerHand() 		// Displays the cards in the players hand
{
	cPlayer::playerHand.showHand();
}
/*
=================
- Determine if the players hand is empty
=================
*/
bool cPlayer::playerHandIsEmpty()			// Determine if there are any cards in the players hand
{
	return cPlayer::playerHand.handIsEmpty();
}

/*
=================
- Flip first card.
=================
*/
void cPlayer::flipFirstCard()        // Flip the first card
{
	if (!(cPlayer::playerHandIsEmpty()))
	{
		cPlayer::playerHand.flipCard();
	}
}
/*
=================
- Displays that the player has won.
=================
*/
void cPlayer::msgPlayerWins()       // Displays that the player has bust.
{
	std::cout << cPlayer::playerName << " you've Won!\n";
}

/*
=================
- Clears the players hand
=================
*/
void cPlayer::clearHand()
{
	if (!(cPlayer::playerHandIsEmpty()))
	{
		cPlayer::playerHand.clearHand();
	}
}
