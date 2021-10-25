#ifndef MEDIALOADER_H
#define MEDIALOADER_H

#include "Texture.h"
#include <SDL2/SDL.h>

class MediaLoader
{
	public:
		MediaLoader(SDL_Renderer* renderer);
		~MediaLoader();
			
	private:
		void free();
		bool loadTexture(SDL_Renderer* renderer);
		Texture* t;
		SDL_Renderer* _renderer;
};

#endif
