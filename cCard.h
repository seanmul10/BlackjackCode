/*
=================
cCard.h
- Header file for class definition - SPECIFICATION
- Header file for the Card class
=================
*/
#ifndef _CCARD_H
#define _CCARD_H
#include "GameConstants.h"

class cCard
{
private:
	CARD aCard;
	
public:
	cCard(ESuit ccSuit, EType ccType, bool ccIsFaceUp);   // Constructor - will create an instance of the card class.
	cCard();              // Constructor - will create an instance of the card class.
	CARD getCard();      // Returns the current card details for the Card instance.
	void showCard();     // Dsiplay on screen the card details for the Card instance.
	short getCardValue();    // Returns the value of the current card.
	void setFaceUp();		// change the value of the card true/false
	string getSuit();		// return card suit
	string getType();		// return card type
	LPCSTR getImage();		// return the filename of the associated card image.
	LPCSTR getCardName();  // return the card name of the associated card image.
};
#endif