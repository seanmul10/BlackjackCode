/*
=================
cCard.cpp
- Header file for class definition - IMPLEMENTATION
=================
*/
#include "cCard.h"
/*
=================
- Data constructor initializes the CARD structure, aCard, to the data passed to 
- the constructor from the paramater nCard.
- Is always called, thus ensures all card objects are in a consistent state.
=================
*/
cCard::cCard()
{
	aCard.cSuit = ESuit::clubs;
	aCard.cType = EType::ace;
	aCard.cValue = (int)EType::ace;
	aCard.cIsFaceUp = true;
}

cCard::cCard(ESuit ccSuit, EType ccType, bool ccIsFaceUp)   // Constructor - will create an instance of the card class.
{
	aCard.cSuit = ccSuit;
	aCard.cType = ccType;
	aCard.cValue = (int)ccType;
	aCard.cValue = cCard::getCardValue();
	aCard.cIsFaceUp = ccIsFaceUp;
}
/*
=================
- Returns the current Card details for the Card instance.
=================
*/

CARD cCard::getCard()        // Returns the current card details for the Card instance.
{
	return aCard;
}
/*
=================
- Displays on screen the current Card details for the Card instance.
=================
*/
void cCard::showCard()     // Dsiplay on screen the card details for the Card instance.
{
	CARD sCard = cCard::getCard();
	if ( sCard.cIsFaceUp )
	{
		std::cout << strType[(short)sCard.cType] << strSuit[(short)sCard.cSuit];
	}
	else
	{
		std::cout << "???\t";
	}

	//std::cout << "Suit    : " << sCard.cSuit << "\n";
	//std::cout << "Type    : " << sCard.cType << "\n";
	//std::cout << "Value   : " << sCard.cValue << "\n";
	//std::cout << "Face Up?: " << sCard.cIsFaceUp << "\n";
}

short cCard::getCardValue()
{
	short gcvValue = 0;
	CARD tCard = cCard::getCard();
	if(tCard.cIsFaceUp)
	{
		gcvValue = tCard.cValue;
		if(gcvValue > 10)
		{
			gcvValue = 10;
		}
	}
	return gcvValue;
}
/*
=================
- Returns the current Card details for the Card instance.
=================
*/

void cCard::setFaceUp()		// change the value of the card true/false
{
	aCard.cIsFaceUp = !(aCard.cIsFaceUp);
}
