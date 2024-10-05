#include "Jotw.h"
#include "Core/Core.h"
#include "Core/Window.h"

int main(int argc, char **argv)
{
	try {
		StartEngineCore();
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	JWindow window;

	SDL_Renderer rend = SDL_CreateRenderer(
		window.GetWindow(),
		-1,
		SDL_RendererFlags::SDL_RENDERER_ACCELERATED
	)

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
				window.ToggleFullscreen();
			}

		}


    }

	QuitEngineCore();
    return (0);
}