#ifndef BTN_H
#define BTN_H

#include "BtnSprite.hh"
#include "ButtonSize.hh"
#include "Texture.hh"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

class Btn
{
	public:
		Btn(Texture* t, SDL_Rect* Clips[Button::bamount]);
		~Btn();
		void setPosition(int x, int y);
		void handleEvent(SDL_Event* e);
		void render();
	private:
		void free();
		Texture* _texture;
		SDL_Rect* _SpriteClips[Button::bamount];
		SDL_Point _position;
		BtnSprite _currentSprite;
};

#endif
