#include <iostream>

#include "Core/Window.h"
#include "Jotw.h"
#include "SDL.h"

FWindow::FWindow() :
	Width(1280),
	Height(780)
{
	Title = "Jotw Engine ";
	Title += __APP__VERSION__;

	Window = SDL_CreateWindow(
		Title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		Width,
		Height,
		SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL
	);
	if (!Window)
	{
		throw(std::runtime_error("Error Creating Window: SDL_CreateWindow() returned NULL"));
	}
}

FWindow::FWindow(uint32_t WindowFlags) :
	Width(1280),
	Height(780)
{
	Title = "Jotw Engine ";
	Title += __APP__VERSION__;

	Window = SDL_CreateWindow(
		Title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		Width,
		Height,
		WindowFlags
	);
	if (!Window)
	{
		throw(std::runtime_error("Error Creating Window: SDL_CreateWindow() returned NULL"));
	}
}

FWindow::~FWindow()
{
	SDL_DestroyWindow(Window);
	if (DEBUG_MODE)
	{
		std::cerr << "DEBUG: Window Destoryed" << std::endl;
	}
}

void FWindow::FullscreenToggle()
{

}

void FWindow::ChangeResolution(uint16_t NewWidth, uint16_t NewHeight, SDL_Renderer* Renderer)
{
	Width = NewWidth;
	Height = NewHeight;
	SDL_RenderSetLogicalSize(Renderer, Width, Height);
}

SDL_Window *FWindow::GetWindow()
{
	return (Window);
}