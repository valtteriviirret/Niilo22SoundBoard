#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Texture
{
	public:
		Texture(SDL_Renderer* renderer);
		~Texture();
		bool loadImage(std::string path);
		void free();
		void setColor(Uint8 red, Uint8 green, Uint8 blue);
		void setBlendMode(SDL_BlendMode blending);
		void setAlpha(Uint8 alpha);

		// render texture at given point
		void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
		
		// getters for dimensions
		int getWidth();
		int getHeight();
	private:
		// the actual texture
		SDL_Texture* _texture;
		
		SDL_Renderer* _renderer;
		int _width;
		int _height;
};

#endif
