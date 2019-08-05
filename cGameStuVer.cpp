/*
==================================================================================
cGame.cpp
==================================================================================
*/
#include "cGame.h"

cGame* cGame::pInstance = NULL;
static cTextureMgr* theTextureMgr = cTextureMgr::getInstance();

/*
=================================================================================
Constructor
=================================================================================
*/
cGame::cGame()
{

}
/*
=================================================================================
Singleton Design Pattern
=================================================================================
*/
cGame* cGame::getInstance()
{
	if (pInstance == NULL)
	{
		pInstance = new cGame();
	}
	return cGame::pInstance;
}


void cGame::initialise(SDL_Window* theSDLWND, SDL_Renderer* theRenderer)
{
	
	// Clear the buffer with a black background
	SDL_SetRenderDrawColor(theRenderer, 0, 0, 0, 255);
	SDL_RenderPresent(theRenderer);


	theTextureMgr->setRenderer(theRenderer);
	theTextureMgr->addTexture("theBackground", "Images/pontoon-blackjack-gold.png");
	
	spriteBkgd.setSpritePos(SDL_Point{ 0,0 });
	spriteBkgd.setTexture(theTextureMgr->getTexture("theBackground"));
	spriteBkgd.setSpriteDimensions(theTextureMgr->getTexture("theBackground")->getTWidth(), theTextureMgr->getTexture("theBackground")->getTHeight());

	// Deal Cards

	for (int deal = 0; deal < 2; deal++)
	{
		theCard = thePack.getCard();
		theDealer.setPlayerHand(theCard);
		theTextureMgr->addTexture(theCard->getCardName(), theCard->getImage());
		theCard = thePack.getCard();
		thePlayer.setPlayerHand(theCard);
		theTextureMgr->addTexture(theCard->getCardName(), theCard->getImage());
	}

	theDealer.flipFirstCard();
}

void cGame::run(SDL_Window* theSDLWND, SDL_Renderer* theRenderer)
{
	bool loop = true;
	this->render(theSDLWND, theRenderer);

	while (loop)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				loop = false;
			}

			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					loop = false;
					break;
				case SDLK_s:
				{
					sStick = true;
					theDealer.flipFirstCard();
				}
				break;

				case SDLK_t:
				{
					if (!(thePlayer.pIsBust()) && !(sStick))
					{
						theCard = thePack.getCard();
						thePlayer.setPlayerHand(theCard);
						theTextureMgr->addTexture(theCard->getCardName(), theCard->getImage());
						this->render(theSDLWND, theRenderer);
					}

				}
				break;
				default:
					break;
				}
			}
		}

		// Lab code goes here

	}
}

void cGame::render(SDL_Window* theSDLWND, SDL_Renderer* theRenderer)
{
	//We get the time that passed since the last frame
	//float elapsedTime = pgmWNDMgr->getElapsedSeconds();

	spriteBkgd.render(theRenderer,NULL, NULL);
	cCard* aCard;

	for (int dealersCard = 0; dealersCard < theDealer.getNumberofCards(); dealersCard++)
	{
		SDL_Point cardPos = SDL_Point{ 180, 100 } + SDL_Point{ (35 * dealersCard), 0 };
		aCard = theDealer.getPlayerCard(dealersCard);
		cardSprite.setSpritePos(cardPos);
		cardSprite.setTexture(theTextureMgr->getTexture(aCard->getCardName()));
		cardSprite.render(theRenderer, &cardSprite.getSpriteDimensions(), &cardSprite.getSpritePos());
	}

	for (int playersCard = 0; playersCard < thePlayer.getNumberofCards(); playersCard++)
	{
		SDL_Point cardPos = SDL_Point{ 180, 300 } +SDL_Point{ (35 * playersCard), 0 };
		aCard = thePlayer.getPlayerCard(playersCard);
		cardSprite.setSpritePos(cardPos);
		cardSprite.setTexture(theTextureMgr->getTexture(aCard->getCardName()));
		cardSprite.render(theRenderer, &cardSprite.getSpriteDimensions(), &cardSprite.getSpritePos());
	}
	// Swap our back buffer to the front
	SDL_RenderPresent(theRenderer);
}

void cGame::cleanUp(SDL_Window* theSDLWND)
{
	// Delete our OpengL context
	SDL_GL_DeleteContext(theSDLWND);

	// Destroy the window
	SDL_DestroyWindow(theSDLWND);

	// Quit IMG system
	IMG_Quit();

	// Shutdown SDL 2
	SDL_Quit();
}

