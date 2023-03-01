#include "utils.h"

SDL_Color dict2SDL_Color(int r, int g, int b) {
	SDL_Color color;
	color.r = r;
	color.g = g;
	color.b = b;
	return color;
}

bool validColorValue(int value) { 
	if (value >=0 && value <= 255) return true;
	else return false;
}

void logSDLError(std::ostream& os, const std::string &msg)
{
	os << msg << " Error: " << SDL_GetError() << std::endl;
}

void initSDL(SDL_Window **window, SDL_Renderer **renderer) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		logSDLError(std::cout, "SDL_Init");
		exit(1);
	}
	*window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	//window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);

	if (*window == nullptr) {
		logSDLError(std::cout, "CreateWindow");
		SDL_Quit();
		exit(1);
	}

	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	//SDL_Renderer *renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
	if (*renderer == nullptr) {
		logSDLError(std::cout, "CreateRenderer");
		SDL_Quit();
		exit(1);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_RenderSetLogicalSize(*renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void quitSDL(SDL_Window **window, SDL_Renderer **renderer)
{
	SDL_DestroyRenderer(*renderer);
	SDL_DestroyWindow(*window);
	SDL_Quit();
}

void waitUntilKeyPressed()
{
	SDL_Event e;
	bool keyPressed = false;
	while (!keyPressed) {
		if (SDL_WaitEvent(&e) != 0) {
			if (e.type == SDL_KEYDOWN) {
				keyPressed = true;
			} else if (e.type == SDL_QUIT) {
				keyPressed = true;
			}
		}
		SDL_Delay(10000);
	}
}