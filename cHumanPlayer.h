/*
=================
cHumanPlayer.h
- Header file for class definition - SPECIFICATION
- Header file for the Human Player class
=================
*/
#ifndef _CHPLAYER_H
#define _CHPLAYER_H
#include "cHand.h"
#include "cPlayer.h"

class cHumanPlayer : public cPlayer
{
private:
	int chips; // The amount of chips the player currently has.
public:
	cHumanPlayer(const std::string& name);   // Constructor - will create an instance of the cHumanPlayer class.
	int pPlay(cHumanPlayer player, int stake);  // Indicates if the player wants to take another card.
	short getChipCount(); // Returns the players current amount of chips.
	void setChipCount(int dChipAmount); // Sets 
};
#endif