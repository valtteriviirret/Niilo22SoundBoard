#ifndef MEDIALOADER_H
#define MEDIALOADER_H

#include "Texture.hh"
#include "BtnSprite.hh"
#include "ScreenSize.hh"
#include "ButtonSize.hh"
#include "Btn.hh"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

// this class loads all media
class MediaLoader
{
	public:
		MediaLoader(SDL_Renderer* renderer);
		~MediaLoader();
		Btn* getBtn(int n);
		SDL_Rect* getSprite(int n);
		Mix_Music* getSound(int n);
			
	private:
		void free();
		bool loadTexture(SDL_Renderer* renderer);
		void setSprites();
		void setButtons();
		bool loadSound();
		Texture* t;
		SDL_Renderer* _renderer;
		SDL_Rect* SpriteClips[Button::bamount];
		Btn* Btns[Button::bamount];
		Mix_Music* sounds[Button::bamount];
};

#endif
