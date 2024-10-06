#ifndef JW_CORE_H
# define JW_CORE_H

#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <cmath>

class FWindow;
class FRenderer;

class FGlobalEngine {
private:

protected:

public:
	FWindow *Window;
	FRenderer *Renderer;

	void Initialize();

};

extern FGlobalEngine* GEngine;

#endif