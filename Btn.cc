#include "Btn.hh"

Btn::Btn(Texture* t, SDL_Rect* Clips[Button::bamount])
{
	_texture = t;
	_position.x = 0;
	_position.y = 0;
	_currentSprite = MOUSE_OUT;

	for(int i = 0; i < Button::bamount; i++)
		_SpriteClips[i] = Clips[i];
}

Btn::~Btn()
{
	free();
}

void Btn::free()
{
	_texture = NULL;
	for(int i = 0; i < Button::bamount; i++)
		_SpriteClips[i] = NULL;
}

void Btn::setPosition(int x, int y)
{
	_position.x = x;
	_position.y = y;
}

void Btn::handleEvent(SDL_Event *e)
{
	// if mouse event happened
	if(e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
	{
		// get mouse position
		int x, y;
		SDL_GetMouseState(&x, &y);

		// check if mouse is in button
		bool inside = true;

		// mouse is in left of the button
		if(x < _position.x)
			inside = false;

		// mouse is right of the button
		else if(x > _position.x + Button::bwidth)
			inside = false;

		// mouse is above the button
		else if(y < _position.y)
			inside = false;

		// mouse below the button
		else if(y > _position.y + Button::bheight)
			inside = false;

		if(!inside)
			_currentSprite = MOUSE_OUT;
		
		// mouse is inside button
		else
		{
			// set mouse over sprite
			switch(e -> type)
			{
				case SDL_MOUSEMOTION: _currentSprite = MOUSE_OVER; break;
				case SDL_MOUSEBUTTONDOWN: 
				_currentSprite = MOUSE_DOWN; 
				break;
				case SDL_MOUSEBUTTONUP: _currentSprite = MOUSE_UP; break;
			}
		}
	}		
}

void Btn::render()
{
	_texture->render(_position.x, _position.y, _SpriteClips[_currentSprite]);
}

