#include "MediaLoader.hh"

MediaLoader::MediaLoader(SDL_Renderer* renderer)
{
	_renderer = renderer;
	loadTexture(renderer);

	for(int i = 0; i < Button::bamount; i++)
		SpriteClips[i] = new SDL_Rect;

	setSprites();
	loadSound();
	setButtons();
}

MediaLoader::~MediaLoader() { free(); }

void MediaLoader::setButtons()
{
	// create new buttons and set them to the screen
	for(int i = 0; i < Button::bamount; i++)
		Btns[i] = new Btn(t, SpriteClips, sounds[i]);

	Btns[0]->setPosition(0, 0);
	Btns[1]->setPosition(Button::bwidth, 0);
	Btns[2]->setPosition((2 * Button::bwidth), 0);
	Btns[3]->setPosition((3 * Button::bwidth), 0);
	
	Btns[4]->setPosition(0, Button::bheight);
	Btns[5]->setPosition(Button::bwidth, Button::bheight);
	Btns[6]->setPosition((2 * Button::bwidth), Button::bheight);
	Btns[7]->setPosition((3 * Button::bwidth), Button::bheight);

	Btns[8]->setPosition(0, (2 * Button::bheight));
	Btns[9]->setPosition(Button::bwidth, (2 * Button::bheight));
	Btns[10]->setPosition((2 * Button::bwidth), (2 * Button::bheight));
	Btns[11]->setPosition((3 * Button::bwidth), (2 * Button::bheight));

	Btns[12]->setPosition(0, (3 * Button::bheight));
	Btns[13]->setPosition(Button::bwidth, (3 * Button::bheight));
	Btns[14]->setPosition((2 * Button::bwidth), (3 * Button::bheight));
	Btns[15]->setPosition((3 * Button::bwidth), (3 * Button::bheight));

}

bool MediaLoader::loadTexture(SDL_Renderer* renderer)
{
	// load images
	bool w = true;
	
	t = new Texture(renderer);
	if(!t->loadImage("images/image.png"))
	{
		std::cout << "Failed to load texture!\n";
		w = false;
	}
	return w;
}

void MediaLoader::setSprites()
{
	// set sprites from the picture
	for(int i = 0; i < Button::bamount; ++i)
	{
		SpriteClips[i]->x = 0;
		SpriteClips[i]->y = i * 100;
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
	for(int i = 0; i < 16; i++)
	{
		Mix_FreeMusic(sounds[i]);
		sounds[i] = NULL;
	}
}

bool MediaLoader::loadSound()
{
	// flag
	bool w = true;

	// load sound clips
	sounds[0] = Mix_LoadMUS("sounds/niilo0.mp3");
	sounds[1] = Mix_LoadMUS("sounds/niilo1.mp3");
	sounds[2] = Mix_LoadMUS("sounds/niilo2.mp3");
	sounds[3] = Mix_LoadMUS("sounds/niilo3.mp3");
	sounds[4] = Mix_LoadMUS("sounds/niilo4.mp3");
	sounds[5] = Mix_LoadMUS("sounds/niilo5.mp3");
	sounds[6] = Mix_LoadMUS("sounds/niilo6.mp3");
	sounds[7] = Mix_LoadMUS("sounds/niilo7.mp3");
	sounds[8] = Mix_LoadMUS("sounds/niilo8.mp3");
	sounds[9] = Mix_LoadMUS("sounds/niilo9.mp3");
	sounds[10] = Mix_LoadMUS("sounds/niilo10.mp3");
	sounds[11] = Mix_LoadMUS("sounds/niilo11.mp3");
	sounds[12] = Mix_LoadMUS("sounds/niilo12.mp3");
	sounds[13] = Mix_LoadMUS("sounds/niilo13.mp3");
	sounds[14] = Mix_LoadMUS("sounds/niilo14.mp3");
	sounds[15] = Mix_LoadMUS("sounds/niilo15.mp3");
	
	// check if everything loaded properly
	for(int i = 0; i < 16; i++)
		if(sounds[i] == NULL)
		{
			std::cout << "Failed to load music file " << i << "Error: " << Mix_GetError() << "\n"; 
			w = false;
		}
	return w;
}

// getters
Btn* MediaLoader::getBtn(int n) { return Btns[n]; } 
Mix_Music* MediaLoader::getSound(int n){ return sounds[n]; }

