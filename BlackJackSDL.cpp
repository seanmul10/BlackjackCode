// C++ Headers
#include <string>
#include <iostream>

// OpenGL / glew Headers
#define GL3_PROTOTYPES 1
//#include <GL\glew.h>

// SDL2 Headers
#include <SDL.h>

#include "cSDL2WNDManager.h"
#include "cGame.h"

using namespace std;

string windowTitle = "BlackJack SDL - Rework of console app!";

//This is the SDL window
static cSDL2WNDManager* pgmWNDMgr = cSDL2WNDManager::getInstance();

//This is the our Game
static cGame* theGame = cGame::getInstance();

int main(int argc, char *argv[])
{
	if (!pgmWNDMgr->initWND(windowTitle, 800, 600))
		return -1;

	theGame->initialise(pgmWNDMgr->getSDLWindow(), pgmWNDMgr->getSDLRenderer());

	theGame->run(pgmWNDMgr->getSDLWindow(), pgmWNDMgr->getSDLRenderer());

	theGame->cleanUp(pgmWNDMgr->getSDLWindow());

	return 0;
}

