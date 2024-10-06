#ifndef JW_WINDOW_H
# define JW_WINDOW_H

class SDL_Window;
class SDL_Renderer;
enum SDL_WindowFlags : int;

class FWindow {
private:
	SDL_Window *Window;
	std::string Title;
	uint16_t Height;
	uint16_t Width;
	bool bIsFullscreen;

public:
	FWindow();
	FWindow(const std::string& Title, uint16_t Width, uint16_t Height, SDL_WindowFlags Flags);

	~FWindow();

	SDL_Window *GetWindow();

	void ToggleFullscreen();
	void UpdateScreenSize(const uint16_t Width, const uint16_t Height);
};

#endif