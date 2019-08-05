/*
=================
cSprite.h
- Header file for class definition - SPECIFICATION
- Header file for the Sprite class
=================
*/
#ifndef _CSPRITE_H
#define _CSPRITE_H
#include "GameConstants.h"
#include "cTexture.h"

class cSprite
{
private:
	// position
	SDL_Rect spritePos_2D;
	SDL_Rect spriteDimensions;

	// Pointer to Sprite Texture
	cTexture* spriteTexture;

	// Texture width & Height
	int textureWidth;
	int textureHeight;


public:
	cSprite();			// Default constructor
	cSprite(cTexture* theSpriteTexture);			// Default constructor
	~cSprite();			// Destructor
	void render(SDL_Renderer* theRenderer, SDL_Rect* theSourceRect, SDL_Rect* theDestRect);
	SDL_Rect getSpritePos();  // Return the sprites current position
	void setSpritePos(SDL_Point sPosition); // set the position of the sprite
	cTexture* getTexture();  // Return the sprites current image
	void setTexture(cTexture* theSpriteTexture);  // set the image of the sprite
	void setSpriteDimensions(int texWidth, int textHeight);
	SDL_Rect getSpriteDimensions(); // Return sprite dimensions

};
#endif