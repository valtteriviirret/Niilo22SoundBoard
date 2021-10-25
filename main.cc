#include "Renderer.hh"
#include "MediaLoader.hh"
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
		
		// load the media
		MediaLoader m(r.getRenderer());

		// main loop flag
		bool q = false;

		// event handler
		SDL_Event e;
	
		while(!q)
		{
			// handle events on queue
			while(SDL_PollEvent(&e) != 0)
			{
				// user requests quit
				if(e.type == SDL_QUIT)
					q = true;
				
				// handle button events
				for(int i = 0; i < Button::bamount; ++i)
					m.getBtn(i)->handleEvent(&e);
			}

			// clear screen
			SDL_SetRenderDrawColor(r.getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(r.getRenderer());

			// render buttons
			for(int i = 0; i < Button::bamount; ++i)
				m.getBtn(i)->render();

			// update screen
			SDL_RenderPresent(r.getRenderer());
		}
	}

	// close SDL
	IMG_Quit();
	SDL_Quit();
	
	return 0;
}
