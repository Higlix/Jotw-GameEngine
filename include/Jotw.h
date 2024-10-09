#ifndef JW_JOTW_H
# define JW_JOTW_H

#define APP_NAME "Jotw"
#define __APP__VERSION__ "0.0.1"

#define DEBUG_MODE 1

#include <stdint.h>

class SDL_Window;

void InitializeEngineCore(uint32_t Flags);
void InitializeWindow(uint32_t Flags);
void InitializeRenderer(SDL_Window *Window, uint32_t Flags);
void QuitEngineCore();


#endif