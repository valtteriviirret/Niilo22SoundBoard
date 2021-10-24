#include "Texture.h"

Texture::Texture(SDL_Renderer* renderer)
{
	_texture = NULL;
	_width = 0;
	_height = 0;
	_renderer = renderer;
}

Texture::~Texture() { free(); }

bool Texture::loadImage(std::string path)
{
	// destroy old texture
	free();

	// final texture
	SDL_Texture* newTexture = NULL;

	// load image at path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if(loadedSurface == NULL)
		std::cout << "Unable to load image " << path.c_str() << "SDL_image Error: " << IMG_GetError() << "\n";
	else
	{
		// color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		// create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
		if(newTexture == NULL)
			std::cout << "Unable to create texture " << path.c_str() << "SDL Error " << SDL_GetError() << "\n";
		else
		{
			// get image dimensions
			_width = loadedSurface->w;
			_height = loadedSurface->h;
		}
		// get rid of the loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	// return success
	_texture = newTexture;
	return _texture != NULL;
}

void Texture::free()
{
	// free texture if it exists
	if(_texture != NULL)
	{
		SDL_DestroyTexture(_texture);
		_texture = NULL;
		_renderer = NULL;
		_width = 0;
		_height = 0;
	}
}

void Texture::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	SDL_SetTextureColorMod(_texture, red, green , blue);
}

void Texture::setBlendMode(SDL_BlendMode blending)
{
	SDL_SetTextureBlendMode(_texture, blending);
}

void Texture::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(_texture, alpha);
}

void Texture::render(int x, int y, SDL_Rect *clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	// set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, _width, _height };

	// set clip rendering dimensions
	if(clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	// render to screen
	SDL_RenderCopyEx(_renderer, _texture, clip, &renderQuad, angle, center, flip);
}

int Texture::getWidth() { return _width; }

int Texture::getHeight() { return _height; }

