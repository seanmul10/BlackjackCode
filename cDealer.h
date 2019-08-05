/*
=================
cDealer.h
- Header file for class definition - SPECIFICATION
- Header file for the Dealer class
=================
*/
#ifndef _CDEALER_H
#define _CDEALER_H
#include "cHand.h"
#include "cPlayer.h"

class cDealer : public cPlayer
{
public:
	cDealer(const std::string& name = "Dealer");   // Constructor - will create an instance of the cDealer class.
	virtual bool pIsTwisting();  // Indicates if the player wants to take another card. 
};
#endif