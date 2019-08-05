/*
=================
cSprite.cpp
- Header file for class definition - IMPLEMENTATION
=================
*/
#include "cSprite.h"
/*
=================
- Data constructor initializes the cSprite to the data passed to 
- the constructor from the paramater sPosition.
- Is always called, thus ensures all sprite objects are in a consistent state.
=================
*/
cSprite::cSprite() 			// Default constructor
{

	this->spritePos_2D = {0};
	this->spriteTexture = NULL;
}

cSprite::cSprite(cTexture* theSpriteTexture) 			// Default constructor
{
	this->spriteTexture = theSpriteTexture;
	this->setSpriteDimensions(this->spriteTexture->getTWidth(), this->spriteTexture->getTHeight());
	this->spritePos_2D = { 0, 0, this->spriteTexture->getTWidth(), this->spriteTexture->getTHeight() };
}

/*
=================
- Destructor 
=================
*/
cSprite::~cSprite()			// Destructor
{
}
/*
=================
- Return the sprites current position.
=================
*/

SDL_Rect cSprite::getSpritePos()  // Return the sprites current position
{
	return this->spritePos_2D;
}

/*
=================
- set the position of the sprite.
=================
*/

void cSprite::setSpritePos(SDL_Point sPosition)  // set the position of the sprite
{
	this->spritePos_2D.x = sPosition.x;
	this->spritePos_2D.y = sPosition.y;
}

/*
=================
- Return the sprites current image.
=================
*/

cTexture* cSprite::getTexture()  // Return the sprites current image
{
	return this->spriteTexture;
}

/*
=================
- set the image of the sprite.
=================
*/

void cSprite::setTexture(cTexture* theSpriteTexture)  // set the image of the sprite
{
	this->spriteTexture = theSpriteTexture;
	this->setSpriteDimensions(spriteTexture->getTWidth(), spriteTexture->getTHeight());
	this->spritePos_2D.w = textureWidth;
	this->spritePos_2D.h = textureHeight;
}


void cSprite::render(SDL_Renderer* theRenderer, SDL_Rect* theSourceRect, SDL_Rect* theDestRect)
{
	this->spriteTexture->renderTexture(theRenderer, this->spriteTexture->getTexture(), theSourceRect, theDestRect);
}
/*
=================
- Set the sprite dimensions.
=================
*/
void cSprite::setSpriteDimensions(int texWidth, int textHeight)
{
	this->textureWidth = texWidth;
	this->textureHeight = textHeight;
	this->spriteDimensions = { 0, 0, texWidth, textHeight };
}

/*
=================
- Get the sprite dimensions.
=================
*/
SDL_Rect cSprite::getSpriteDimensions()
{
	return this->spriteDimensions;
}