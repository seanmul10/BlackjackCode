/*
=================
cPack.cpp
- Header file for class definition - IMPLEMENTATION
=================
*/
#include "cPack.h"
/*
=================
- Data constructor initializes the Pack 
- Is always called, thus ensures all card objects are in a consistent state.
=================
*/

cPack::cPack()   // Constructor - will create an instance of the card class.
{
	cPack::mPack.reserve(52);     // defines an array a temporary array of cards
	cPack::mPack.clear();
	cPack::createPack();
	cPack::shufflePack();
}
/*
=================
- Returns the current Card details for the Card instance.
=================
*/

void cPack::createPack()        // Returns the current card details for the Card instance.
{
	for (ESuit theSuit = ESuit::clubs; theSuit <= ESuit::spades; ++theSuit)
	{
		for (EType theCard = EType::ace; theCard <= EType::king; ++theCard)
		{
			cPack::mPack.push_back(new cCard(static_cast<ESuit>(theSuit), static_cast<EType>(theCard), true));
		}
	}
}
/*
=================
- Displays on screen the current Card details for the Card instance.
=================
*/
void cPack::shufflePack()     // Dsiplay on screen the card details for the Card instance.
{
	/* Let the computer pick a random number */
	// obtain a time-based seed:
	auto seed = chrono::system_clock::now().time_since_epoch().count();
	shuffle(cPack::mPack.begin(), cPack::mPack.end(), default_random_engine((unsigned)seed));
}

/*
=================
- Displays on screen the current Card details for the Card instance.
=================
*/
cCard* cPack::getCard()       // Get a card from the top of the pack
{
	cCard* aCard;
	aCard = cPack::mPack.back();
	cPack::mPack.pop_back();
	return aCard;
}
