#ifndef MEDIALOADER_H
#define MEDIALOADER_H

#include "Texture.h"
#include "BtnSprite.h"
#include "ScreenSize.h"
#include "ButtonSize.h"
#include <SDL2/SDL.h>

class MediaLoader
{
	public:
		MediaLoader(SDL_Renderer* renderer);
		~MediaLoader();
			
	private:
		void free();
		bool loadTexture(SDL_Renderer* renderer);
		void setSprites();
		void setButtons();
		Texture* t;
		SDL_Renderer* _renderer;
		SDL_Rect SpriteClips[Button::bamount];
};

#endif
