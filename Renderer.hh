#ifndef RENDERER_H
#define RENDERER_H

#include "Window.hh"
#include <SDL2/SDL.h>
#include <iostream>

// this class creates the renderer
class Renderer
{
	public:
		Renderer();
		~Renderer();
		SDL_Renderer* getRenderer();
	private:
		SDL_Renderer* renderer;
		void free();
		bool CreateRenderer();
		Window* window;
};

#endif
