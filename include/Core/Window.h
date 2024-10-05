#pragma once
#include "Core/Core.h"

class SDL_Window;
class SDL_Renderer;

class JWindow {
private:
	SDL_Window *Window;
	std::string Title;
	uint16_t Height;
	uint16_t Width;
	bool bIsFullscreen;

public:
	JWindow();
	JWindow(const std::string& Title, uint16_t Width, uint16_t Height, SDL_WindowFlags Flags);

	~JWindow();


	SDL_Window *GetWindow();
	void ToggleFullscreen();
};