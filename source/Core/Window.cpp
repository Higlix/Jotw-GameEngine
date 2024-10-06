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
}

SDL_Window *FWindow::GetWindow()
{
	return (Window);
}