#ifndef _GAMECONSTANTS_H
#define _GAMECONSTANTS_H

// Windows & OpenGL & SDL
#include <stdlib.h>
#include <Windows.h>
//#include <GL\glut.h>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <SDL.h>

// Image Texture loading library
#include <SDL_image.h>
// Font loading library
#include <SDL_ttf.h>
// Sound loading library
#include <SDL_mixer.h>


// STL Container & Algorithms
#include <vector>
#include <map>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

//Define the string to appear in the top left corner of the window
#define WINDOW_TITLE "BlackJackSDL - Console app reworked!"

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

inline ESuit operator++(ESuit& x) { return x = static_cast<ESuit>((static_cast<int>(x) + 1)); }
inline EType operator++(EType& x) { return x = static_cast<EType>((static_cast<int>(x) + 1)); }

const LPCSTR strType[14] = { "0", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };
const LPCSTR strSuit[4] = { " of Clubs\t", " of Diamonds\t", " of Hearts\t", " of Spades\t" };

struct CARD{
	ESuit cSuit;       // Suit card belongs to.
	EType cType;       // Type of card e.g. face card.
	short cValue;      // Numeric value of the playing card
	bool cIsFaceUp;
	string cFilename;
	string cCardName;
};

inline SDL_Point operator+(SDL_Point const &a, SDL_Point const &b)
{
	return SDL_Point{ a.x + b.x , a.y + b.y };
}

#endif