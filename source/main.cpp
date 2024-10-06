#include "Jotw.h"
#include "Core/Core.h"
#include "Core/Window.h"
#include "Core/Renderer.h"
#include "SDL.h"

int main(int argc, char **argv)
{
	try {
		InitializeEngineCore(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS);
		InitializeWindow(SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
		InitializeRenderer(GEngine->Window->GetWindow(), SDL_RENDERER_ACCELERATED);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	while (true)
    {
    	// Get the next event
		SDL_Event event;
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
			// Break out of the loop on quit
			break;
			}
			if (event.key.keysym.sym == SDLK_F11)
			{
				// window.ToggleFullscreen();
			}
		}
		SDL_SetRenderDrawColor(GEngine->Renderer->GetRenderer(), 100, 149, 237, 255);
		SDL_RenderClear(GEngine->Renderer->GetRenderer());
		// Show the renderer contents
		SDL_RenderPresent(GEngine->Renderer->GetRenderer());
	}

	QuitEngineCore();
    return (0);
}