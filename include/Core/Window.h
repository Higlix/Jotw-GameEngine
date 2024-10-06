#ifndef JW_WINDOW_H
# define JW_WINDOW_H

#include <iostream>
#include <cstdint>

struct SDL_Window;

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

	SDL_Window *GetWindow();
};

#endif