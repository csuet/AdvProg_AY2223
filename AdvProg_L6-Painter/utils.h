#ifndef UTILS_H
#define UTILS_H

#include <iostream>

#if defined(_WIN64) || defined(_WIN32)
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif

#if defined(_WIN64) || defined(_WIN32)
    #include <SDL_image.h>
#else
    #include <SDL2/SDL_image.h>
#endif

const int SCREEN_WIDTH  = 800;
const int SCREEN_HEIGHT = 600;

const std::string WINDOW_TITLE = "An Implementation of Code.org Painter";

SDL_Color dict2SDL_Color(int r, int g, int b);
bool validColorValue(int value);
void initSDL(SDL_Window **window, SDL_Renderer **renderer);
void quitSDL(SDL_Window **window, SDL_Renderer **renderer);
void waitUntilKeyPressed();
void logSDLError(std::ostream& os, const std::string &msg);


#endif