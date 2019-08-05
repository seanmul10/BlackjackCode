/*
=================
cPack.h
- Header file for class definition - SPECIFICATION
- Header file for the Pack class
=================
*/
#ifndef _CPACK_H
#define _CPACK_H
#include "cCard.h"

class cPack
{
private:
	std::vector<cCard*> mPack;     // defines an array of cards
	void createPack();   // used to create a sequential pack of cards
	
public:
	cPack();              // Constructor - will create an instance of the pack class.
	void shufflePack();   // shuffles the pack.
	cCard* getCard();       // Get a card from the top of the pack
};
#endif