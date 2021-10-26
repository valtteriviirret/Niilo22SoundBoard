#include "Renderer.hh"

Renderer::Renderer()
{
	CreateRenderer();
}

Renderer::~Renderer()
{
	free();
}

bool Renderer::CreateRenderer()
{
	bool w = true;

	window = new Window;

	// create the renderer
	renderer = SDL_CreateRenderer(window->getWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(renderer == NULL)
	{
		std::cout << "Renderer could not be created! Error: " << SDL_GetError() << "\n";
		w = false;
	}
	// initialize color
	else
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	return w;
}

void Renderer::free()
{
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	delete window;
}

SDL_Renderer* Renderer::getRenderer() { return renderer; }

