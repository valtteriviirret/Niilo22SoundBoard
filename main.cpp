#include "Window.h"
#include "Renderer.h"
#include "MediaLoader.h"
#include <SDL2/SDL_image.h>

int main()
{
	// initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		std::cout << "SDL could not initialize! Error: " << SDL_GetError() << "\n";
	else
	{
		// set texture filtering to linear
		if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
			std::cout << "Linear texture filtering not enabled\n";

		// create the renderer
		Renderer r;
		
		// initialize PNG loading
		int imgFlags = IMG_INIT_PNG;
		if(!(IMG_Init(imgFlags) &imgFlags))
			std::cout << "SDL_image could not initialize! SDL_Image Error:" << IMG_GetError() << "\n";
		
		MediaLoader m(r.getRenderer());
	}

	SDL_Delay(10000);
	IMG_Quit();
	SDL_Quit();
	
	return 0;
}
