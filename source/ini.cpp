#include <iostream>

#include "Core/Core.h"
#include "Core/Window.h"
#include "Core/Renderer.h"
#include "SDL.h"

void InitializeEngineCore(Uint32 Flags)
{
	GEngine = (FGlobalEngine *) malloc(sizeof(FGlobalEngine));
	if (GEngine == nullptr)
	{
		throw(std::runtime_error("GEngine failed to initialize: malloc returned NULL\n"));
	}
	GEngine->Initialize();

	if (SDL_Init(Flags) < 0)
    {
        throw(std::runtime_error("Failed to initialize the SDL2 library\n"));
    }
}

void InitializeWindow(Uint32 Flags)
{
	FWindow *window = new FWindow(Flags);

	if (!window)
	{
		throw(std::runtime_error("FWindow failed to initalize"));
	}
	GEngine->Window = window;
}

void InitializeRenderer(SDL_Window *Window, Uint32 Flags)
{
	FRenderer *renderer = new FRenderer(Window, -1, Flags);

	if (!renderer)
	{
		throw(std::runtime_error("FRenderer failed to initalize"));
	}
	GEngine->Renderer = renderer;
}

void QuitEngineCore()
{
	delete (GEngine->Renderer);
	delete (GEngine->Window);
	free(GEngine);
	SDL_Quit();
}