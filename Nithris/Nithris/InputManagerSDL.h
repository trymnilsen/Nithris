//PG4400 - INNLEVERING 1 - TRYM NILSEN
////////////////////////////////////////////////////////////////////////////////
//																			  //
//	File: InputManagerSDL.h													  //
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

#ifndef INPUTMANAGERSDL_H
#define INPUTMANAGERSDL_H

#include <memory>
#include <SDL.h>

class InputManagerSDL
{
public:
	/* A Meyer's singleton instance call. Use this to access the member functions */
	static InputManagerSDL& Instance()
	{
		static InputManagerSDL iM;
		return iM;
	}

	/* Updates the key snapshot array. Must be called once per frame (per loop) in order for this to work. */
	void Update();

	/* Whether the user has closed (X-ed out) the window or not. */
	inline bool userExit() const { return m_exit; }

	//---------------------//
	// Keyboard functions. //
	//--------------------//

	/* Wheter the given key has been pressed or not. NB: use SDL_SCANCODE_XXX */
	bool KeyDown(int keyIndex) const		 { return (CurKeyDown(keyIndex)) && (!OldKeyDown(keyIndex)); }

	/* Wheter the given key has been pressed and is still down, or not. NB: use SDL_SCANCODE_XXX */
	bool KeyStillDown(int keyIndex) const	 { return (CurKeyDown(keyIndex)) && ( OldKeyDown(keyIndex)); }

	/* Whether the given key has been release or not. NB: use SDL_SCANCODE_XXX */
	bool KeyUp(int keyIndex) const			 { return (!CurKeyDown(keyIndex)) && (OldKeyDown(keyIndex)); }

	/* Wheter the given key has been released and is still released, or not. NB: use SDL_SCANCODE_XXX */
	bool KeyStillUp(int keyIndex) const		 { return (!CurKeyDown(keyIndex)) && (!OldKeyDown(keyIndex)); }

	//------------------//
	// Mouse functions. //
	//-----------------//

	/* Wheter the given mouse button has been pressed or not. NB: use SDL_BUTTON_XXX */
	bool MouseDown(int button)		{ return ( CurMouseDown(button))&&(!OldMouseDown(button)); }

	/* Wheter the given mouse button has been pressed and is still down, or not. NB: use SDL_BUTTON_XXX */
	bool MouseStillDown(int button)	{ return ( CurMouseDown(button))&&( OldMouseDown(button)); }

	/* Wheter the given mouse button has been released or not. NB: use SDL_BUTTON_XXX */
	bool MouseUp(int button)		{ return (!CurMouseDown(button))&&( OldMouseDown(button)); }

	/* Wheter the given mouse button has been released and is still released, or not. NB: use SDL_BUTTON_XXX */
	bool MouseStillUp(int button)	{ return (!CurMouseDown(button))&&(!OldMouseDown(button)); }
protected:
	//-----------------------------------------//
	// Helper functions to make things easier. //
	//----------------------------------------//

	bool CurKeyDown(const int& keyIndex) const { return (m_keys[keyIndex] != 0); }
	bool OldKeyDown(const int& keyIndex) const { return (m_oldKeys.get()[keyIndex] != 0); }
	bool CurMouseDown(const int& button) const { return (m_mouseButtons & SDL_BUTTON(button)) != 0; }
	bool OldMouseDown(const int& button) const { return (m_oldMouseButtons & SDL_BUTTON(button)) != 0; }

	Uint8* m_keys;    // A pointer to SDL's internal key state array. (Memory handled by SDL.)
	std::unique_ptr<Uint8> m_oldKeys; // Our own copy of last update's array. NB! Memory handled dynamically by us!
	int m_keyCount;  // Number of keys in the arrays above, for this application. (Can vary depending on setup/hardware.)

	int m_mouseX; // Mouse pos x.
	int m_mouseY; // Mouse pos y.
	Uint8 m_mouseButtons; // Mouse buttons clicked
	Uint8 m_oldMouseButtons; // Mouse buttons clicked last update

	bool m_exit; // If user has requested an exit or not.
private:
	// Private singleton assigners
	InputManagerSDL(); // Hidden constructor
	InputManagerSDL(const InputManagerSDL&); // Hidden copy constructor
	InputManagerSDL& operator=(const InputManagerSDL&); // Hidden assign operator
};
#endif