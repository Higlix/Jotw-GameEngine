#ifndef JW_WINDOW_H
# define JW_WINDOW_H

#include <iostream>
#include <cstdint>

struct SDL_Window;
class SDL_Renderer;

class FWindow {
private:
	SDL_Window *Window;
	std::string Title;
	uint16_t Height;
	uint16_t Width;
	uint32_t WindowFlags;
public:
	FWindow();
	FWindow(uint32_t WindowFlags);

	~FWindow();

	void FullscreenToggle();
	void ChangeResolution(uint16_t NewWidth, uint16_t NewHeight, SDL_Renderer *Renderer);

	SDL_Window *GetWindow();
};

#endif