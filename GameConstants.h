#ifndef _GAMECONSTANTS_H
#define _GAMECONSTANTS_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

// This header file contains all the constants & enumarated types for the game

// ==============================================================================================
// Old C-Style declarations for enumerated types
// enum eSuit {CLUBS,DIAMONDS,HEARTS,SPADES};
// enum eType {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
// ==============================================================================================

// ======================================================
// Newer C++11 Standard declarations for enumerated types
// ======================================================
enum class ESuit { clubs, diamonds, hearts, spades };
enum class EType { ace = 1, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king };

inline ESuit operator++(ESuit& x) { return x = static_cast<ESuit>((static_cast<int>(x)+1)); }
inline EType operator++(EType& x) { return x = static_cast<EType>((static_cast<int>(x)+1)); }

const std::string strType[14] = {"0","Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
const std::string strSuit[4] = {" of Clubs\t"," of Diamonds\t"," of Hearts\t"," of Spades\t"};

struct CARD{
	ESuit cSuit;       // Suit card belongs to.
	EType cType;       // Type of card e.g. face card.
	short cValue;      // Numeric value of the playing card
	bool cIsFaceUp;
};
#endif