#ifndef MEDIALOADER_H
#define MEDIALOADER_H

#include "Texture.hh"
#include "BtnSprite.hh"
#include "ScreenSize.hh"
#include "ButtonSize.hh"
#include "Btn.hh"
#include <SDL2/SDL.h>

class MediaLoader
{
	public:
		MediaLoader(SDL_Renderer* renderer);
		~MediaLoader();
		Btn* getBtn(int n);
		SDL_Rect* getSprite(int n);
			
	private:
		void free();
		bool loadTexture(SDL_Renderer* renderer);
		void setSprites();
		void setButtons();
		Texture* t;
		SDL_Renderer* _renderer;
		SDL_Rect* SpriteClips[Button::bamount];
		Btn* Btns[Button::bamount];
};

#endif
