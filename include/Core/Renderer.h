#ifndef JW_RENDERER_H
# define JW_RENDERER_H

#include <iostream>
#include <cstdint>

class SDL_Renderer;
class SDL_Window;

class FRenderer {
private:
	SDL_Renderer* Renderer;
	uint32_t RendererFlags;

public:
	FRenderer(SDL_Window *Window, int Index);
	FRenderer(SDL_Window *Window, int Index, uint32_t Flags);

	~FRenderer();

	SDL_Renderer* GetRenderer();
};

#endif