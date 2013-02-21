////////////////////////////////////////////////////////////////////////////////
//																			  //
//	File: InputManagerSDL.cpp												  //
//																			  //
//	Original author: Kjetil Raaen / NITH / 2009-2012						  //
//  Great modifications by: Stig M. Halvorsen  / NITH / 2013				  //
//	Changed by: -															  //
//																			  //
//	Descr.: A singleton helper class for capturing user input				  //
//																			  //
//	Special notes: Requires the SDL2 library. Use the use SDL_SCANCODE_XXX	  //
//				   to check for user input. See "SDL_scancode.h" in the SDL	  //
//				   include directory for options. Use SDL_BUTTON_XXX for	  //
//				   mouse input, see "SDL_mouse.h" for options.				  //
//																			  //
////////////////////////////////////////////////////////////////////////////////

#include "InputManagerSDL.h"

InputManagerSDL::InputManagerSDL()
{
	m_keys = NULL;
	m_oldKeys = NULL;
	m_keyCount = NULL;
	m_mouseButtons = NULL;
	m_oldMouseButtons = NULL;
	m_mouseX = NULL;
	m_mouseY = NULL;
	m_exit = false;

	// Creating an array for the current state is taken care of by SDL, so we just get ourselves a 
	// pointer to it. (Array will be deleted by SDL on app exit, so we can forget all about it.)
	m_keys = SDL_GetKeyboardState(&m_keyCount);

	// Allocate sufficent memory for the old keys array
	m_oldKeys = std::unique_ptr<Uint8>(new Uint8[m_keyCount]);

	// Copy over the key states
	memcpy(m_oldKeys.get(), m_keys, m_keyCount * sizeof(Uint8));

	// Pumping twice, to flush any pending keypresses.
	SDL_PumpEvents();
	SDL_PumpEvents();
}

void InputManagerSDL::Update()
{
	// Setting "old" states equal to those aquired on last Update().
	m_oldMouseButtons = m_mouseButtons;
	memcpy(m_oldKeys.get(), m_keys, m_keyCount * sizeof(Uint8));

	// SDL_PollEvent() performs a SDL_PumpEvent() call;
	// Pumping events, meaning we update SDL's input states to match current inputs.
	// Key changes gets updated automatically, as we hold a pointer to SDL's internal key array.
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			m_exit = true;
		}
	}

	// We must manually fetch Mouse updates.
	m_mouseButtons = SDL_GetRelativeMouseState(&m_mouseX, &m_mouseY);
}