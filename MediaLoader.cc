#include "MediaLoader.hh"

MediaLoader::MediaLoader(SDL_Renderer* renderer)
{
	_renderer = renderer;
	loadTexture(renderer);

	for(int i = 0; i < Button::bamount; i++)
		SpriteClips[i] = new SDL_Rect;

	setSprites();
	setButtons();
}

MediaLoader::~MediaLoader()
{
	free();
}

void MediaLoader::setButtons()
{
	for(int i = 0; i < Button::bamount; i++)
		Btns[i] = new Btn(t, SpriteClips);
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

void MediaLoader::setSprites()
{
	for(int i = 0; i < Button::bamount; ++i)
	{
		SpriteClips[i]->x = 0;
		SpriteClips[i]->y = i * 200;
		SpriteClips[i]->w = Button::bwidth;
		SpriteClips[i]->h = Button::bheight;
	}
}

void MediaLoader::free()
{
	delete t;
	_renderer = NULL;
	for(int i = 0; i < Button::bamount; i++)
	{
		delete Btns[i];
		delete SpriteClips[i];
	}
}

Btn* MediaLoader::getBtn(int n) { return Btns[n]; } 

