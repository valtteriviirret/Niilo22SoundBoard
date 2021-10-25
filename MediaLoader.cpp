#include "MediaLoader.h"

MediaLoader::MediaLoader(SDL_Renderer* renderer)
{
	_renderer = renderer;
	loadTexture(renderer);
}

MediaLoader::~MediaLoader()
{
	free();
}

bool MediaLoader::loadTexture(SDL_Renderer* renderer)
{
	bool w = true;
	
	t = new Texture(renderer);
	if(!t->loadImage("button.png"))
	{
		std::cout << "Failed to load texture!\n";
		w = false;
	}
	return w;
}

void MediaLoader::free()
{
	delete t;
	_renderer = NULL;
}
