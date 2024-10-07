#include <iostream>

#include "Core/Renderer.h"
#include "SDL.h"

FRenderer::FRenderer(SDL_Window *Window, int Index) :
	RendererFlags(SDL_RENDERER_ACCELERATED)
{
	Renderer = SDL_CreateRenderer(
		Window,
		Index,
		RendererFlags
	);

	if (!Renderer)
	{
		throw(std::runtime_error("Failed to create Renderer: SDL_CreateRenderer returned NULL"));
	}
}

FRenderer::FRenderer(SDL_Window *Window, int Index, uint32_t Flags) :
	RendererFlags(Flags)
{
	Renderer = SDL_CreateRenderer(
		Window,
		Index,
		RendererFlags
	);

	if (!Renderer)
	{
		throw(std::runtime_error("Failed to create Renderer: SDL_CreateRenderer returned NULL"));
	}
}

FRenderer::~FRenderer()
{
	SDL_DestroyRenderer(Renderer);
	std::cerr << "DEBUG: Renderer Destoryed" << std::endl;
}

SDL_Renderer* FRenderer::GetRenderer()
{
	return (Renderer);
}