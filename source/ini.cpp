#include "SDL.h"
#include <iostream>

void StartEngineCore()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::runtime_error("Failed to initialize the SDL2 library\n");
    }
}

void QuitEngineCore()
{
	SDL_Quit();
}