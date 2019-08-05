/*
=================
cDealer.cpp
- Header file for class definition - IMPLEMENTATION
=================
*/
#include "cDealer.h"
/*
=================
- Data constructor initializes the human player object 
- Is always called, thus ensures all player objects are in a consistent state.
=================
*/

cDealer::cDealer(const std::string& name): cPlayer(name) // Constructor - will create an instance of the player class.
{
}
/*
=================
- Check if player wants to twist.
=================
*/
bool cDealer::pIsTwisting()     // Returns whether the player wants to "Twist".
{
	return (cPlayer::getPlayerHandValue() <= 16);
}

