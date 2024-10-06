#include "Core/Window.h"
#include "SDL.h"

FWindow::FWindow() :
	Title("EMPTY TITLE"),
	Width(500),
	Height(500),
	bIsFullscreen(false)
{
	Window = SDL_CreateWindow(
		Title.c_str(),
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		Width,
		Height,
		SDL_WINDOW_RESIZABLE
	);

	if (Window == nullptr)
	{
		std::cerr << "Window creation failed" << '\n';
	}
}

FWindow::FWindow(const std::string& Title, uint16_t Width, uint16_t Height, SDL_WindowFlags Flags) :
	Title(Title),
	Width(Width),
	Height(Height),
	bIsFullscreen(bIsFullscreen)
{
	Window = SDL_CreateWindow(
		Title.c_str(),
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		Width,
		Height,
		Flags
	);

	if (Window == nullptr)
	{
		std::cerr << "Window creation failed" << '\n';
	}
}

FWindow::~FWindow()
{
	if (Window)
	{
		SDL_DestroyWindow(Window);
	}
}

void FWindow::ToggleFullscreen()
{
	if (Window)
	{
		if (bIsFullscreen)
		{
			SDL_SetWindowFullscreen(Window, 0);
		}
		else
		{
			SDL_SetWindowFullscreen(Window, SDL_WINDOW_FULLSCREEN_DESKTOP);
		}
	}
}

SDL_Window *FWindow::GetWindow()
{
	return (Window);
}

void FWindow::UpdateScreenSize(const uint16_t Width, const uint16_t Height)
{

}
