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

void initSDLsoftware(SDL_Window **window, SDL_Renderer **renderer) {
	// create a virtual software renderer without a window, used when video device is not available
	SDL_Surface* surface = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32,0,0,0,0);
	*renderer = SDL_CreateSoftwareRenderer(surface);
	*window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_HIDDEN);
}

void initSDL(SDL_Window **window, SDL_Renderer **renderer) {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		logSDLError(std::cout, "SDL_Init");
		std::cout << "The program will still continue without a video device!" << std::endl;
		initSDLsoftware(window, renderer);
		return;
		// exit(1);
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
	bool quit = false;
	while (!quit) {
		while( SDL_PollEvent( &e ) != 0 ) {
	    //User requests quit
	    if( e.type == SDL_QUIT || e.type == SDL_KEYDOWN )
	    {
	        quit = true;
	    }
	  }
	}
}
