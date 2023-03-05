#ifndef PAINTER_H
#define PAINTER_H

#include <cmath>
#include <cstdlib>

//Mac
#include <SDL2/SDL.h>
//Windows
// #include <SDL.h>

const SDL_Color CYAN_COLOR = {0, 255, 255};
const SDL_Color BLUE_COLOR = {0, 0, 255};
const SDL_Color ORANGE_COLOR = {255, 165, 0};
const SDL_Color YELLOW_COLOR = {255, 255, 0};
const SDL_Color LIME_COLOR = {0, 255, 0};
const SDL_Color PURPLE_COLOR = {128, 0, 128};
const SDL_Color RED_COLOR = {255, 0, 0};
const SDL_Color WHITE_COLOR = {255, 255, 255};
const SDL_Color BLACK_COLOR = {0, 0, 0};
const SDL_Color GREEN_COLOR = {0, 128, 0};

const SDL_Color DEFAULT_COLOR = BLACK_COLOR;

/***
   An Implementation of Code.org Painter 
***/
class Painter
{
    private:
        int x, y;
        double angle;
        int width, height;
        SDL_Color color;
        SDL_Renderer *renderer;

    public:
    Painter();
	Painter(SDL_Window* window, SDL_Renderer *renderer);
        void setColor(SDL_Color color);
        SDL_Color getColor() { return color; }
        void setPosition(int x, int y) { this->x = x; this->y = y; }
        int getX() { return x; }
        int getY() { return y; }
        SDL_Renderer* getRenderer() { return this->renderer; }
        void setAngle(double angle) { this->angle = angle; }
        double getAngle() { return angle; }
        int getWidth() { return width; }
        int getHeight() { return height; }
        void clearWithBgColor(SDL_Color bgColor);

        void moveForward(int numPixel);
        void moveBackward(int numPixel);
        void turnLeft(double degree);
        void turnRight(double degree);
        void jumpForward(int numPixel);
        void jumpBackward(int numPixel);
        void createCircle(int radius);
        void randomColor();

        void createParallelogram(int size);
        void createSquare(int size);
};

#endif
