#ifndef _GAME_H
#define _GAME_H

/*
==================================================================================
cGame.h
==================================================================================
*/
//#include <GL\glew.h>
#include <SDL.h>

// Game specific includes
#include "GameConstants.h"
#include "cardGame.h"
#include "cTextureMgr.h"

using namespace std;

class cGame
{
public:
	cGame();

	void initialise(SDL_Window* theSDLWND, SDL_Renderer* theRenderer);
	void run(SDL_Window* theSDLWND, SDL_Renderer* theRenderer);
	void cleanUp(SDL_Window* theSDLWND);
	void render(SDL_Window* theSDLWND, SDL_Renderer* theRenderer);

	static cGame* getInstance();

private:

	static cGame* pInstance;

	// game related variables

	// Sprites for displaying background and card textures
	cSprite spriteBkgd;
	cSprite cardSprite;
	// Game objects
	cDealer theDealer;
	cHumanPlayer thePlayer;
	cPack thePack;
	cCard* theCard = NULL;
	
	bool sStick = false;
	bool bGameOver = false;

};

#endif
