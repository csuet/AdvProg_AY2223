#include <iostream>
#include <ctime>

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

#include "painter.h"
#include "utils.h"

using std::cout;
using std:: endl;


int main(int argc, char* argv[])
{
	srand(time(NULL));
	
	int figNumber = 0;
	if (argc == 2) figNumber = atoi(argv[1]) % 15;
	SDL_Window *window;
	SDL_Renderer *renderer;

	initSDL(&window, &renderer);

    //cout << "An Implementation of Code.org Painter" << endl;

	Painter painter(window, renderer);

	switch (figNumber) {

	/*
    cout << "Width: " << painter.getWidth() << " , Height: " << painter.getHeight() << endl;
    cout << "X: " << painter.getX() << " , Y: " << painter.getY() << endl;
	//*/
	/* Square */
	//*
	case 0:
		painter.setColor(WHITE_COLOR);
		for (int i = 0; i < 4; ++i) {
			painter.moveForward(100);
			painter.turnRight(90);
		}
		break;
	//*/

	/* Triangle */
	//*
	case 1:
		painter.setColor(WHITE_COLOR);
		painter.clearWithBgColor(GREEN_COLOR);
		for (int i = 0; i < 3; ++i) {
			painter.turnLeft(120);
			painter.moveForward(100);
		}
		break;
	//*/

	/* Filled Triangle */
	//*
	case 2: {
		int curX = painter.getX();
		int curY = painter.getY();
		painter.setColor(WHITE_COLOR);
		painter.turnLeft(60);
		int size = 150;
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < 3; ++j) {
				painter.turnLeft(120);
				painter.moveForward(size - i);
			}
			painter.setPosition(curX, curY);
			painter.jumpBackward(i+1);
		}
		painter.setPosition(curX, curY);
		break; }
	//*/


	/* Octagon */
	//*
	case 3:
		painter.setPosition(350, 500);
		painter.setColor(YELLOW_COLOR);
		for (int i = 0; i < 8; ++i) {
			painter.moveForward(150);
			painter.turnLeft(45);
		}
		break;
	//*/

	/* Star of fives */
	//*
	case 4:
		painter.setPosition(350, 200);
		painter.setColor(YELLOW_COLOR);
		for (int i = 0; i < 5; ++i) {
			painter.moveForward(200);
			painter.turnRight(144);
		}
		break;
	//*/

	/* Star of David */
	//*
	case 5:
		painter.setPosition(350, 400);
		painter.setColor(YELLOW_COLOR);
		painter.turnLeft(60);
		for (int i = 0; i < 3; ++i) {
			painter.moveForward(150);
			painter.turnLeft(120);
		}
		painter.turnLeft(30);
		painter.jumpForward((int) (150 * 2 / 1.73205080757)); // sqrt(3) = 1.73205080757
		painter.turnLeft(150);
		for (int i = 0; i < 3; ++i) {
			painter.moveForward(150);
			painter.turnLeft(120);
		}
		break;
	//*/
	
	/* Eight lines crossing at center*/
	//*
	case 6:
		painter.setColor(WHITE_COLOR);
		for (int i = 0; i < 8; ++i) {
			painter.moveForward(100);
			painter.moveBackward(100);
			painter.turnLeft(45);
		}
		break;
	//*/

	/* Six squares */
	//*
	case 7:
		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < 4; ++j) {
				painter.moveForward(100);
				painter.turnRight(90);
			}
			painter.turnLeft(60);
		}
		break;
	//*/
	
	/* Circles in line */
	//*
	case 8:
		painter.setColor(RED_COLOR);
		painter.setPosition(150, 150);
		for (int i = 0; i < 10; ++i) {
			painter.createCircle(100);
			painter.jumpForward(30);
		}
		break;
	//*/
	
	/* Circles in circle */
	//*
	case 9:
		painter.setPosition(350, 150);
		painter.clearWithBgColor(BLACK_COLOR);
		for (int i = 0; i < 20; ++i) {
			painter.randomColor();
			painter.createCircle(100);
			painter.jumpForward(1);
			painter.createCircle(100);
			painter.jumpForward(50);
			painter.turnRight(18);
		}
		break;
	//*/

	/*	Ten squares in circle */
	//*
	case 10:
		painter.setColor(WHITE_COLOR);
		for (int i = 0; i < 10; ++i) {
			//painter.randomColor();
			painter.createSquare(100);
			painter.turnRight(36);
		}
		break;
	//*/

	/* Multitude lines in cicles */
	//*
	case 11:
		for (int i = 0; i < 90; ++i) {
			painter.randomColor();
			painter.moveForward(150);
			painter.jumpBackward(150);
			painter.turnRight(4);
		}
		break;
	//*/
	
	/* Pattern of Ten parallelograms */
	//*
	case 12:
		painter.setColor(WHITE_COLOR);
		for (int i = 0; i < 10; ++i) {
			painter.createParallelogram(100);
			painter.turnRight(36);
		}
		break;
	//*/

	/* Five and five cirles */
	//*
	case 13:
		painter.setColor(WHITE_COLOR);
		painter.clearWithBgColor(GREEN_COLOR);
		for (int i = 0; i < 5; ++i) {
			painter.createCircle(100);
			painter.createCircle(50);
			painter.turnRight(72);
		}
		break;
	//*/

	/* Snow flake*/
	//*
	case 14: {
		painter.setColor(WHITE_COLOR);
		for (int i = 0; i < 8; ++i) {
			int size = 40;
			painter.moveForward(size);
			for (int j = 0; j < 3; ++j) {
				painter.turnLeft(45);
				painter.moveForward(size);
				painter.jumpBackward(size);
				painter.turnRight(90);
				painter.moveForward(size);
				painter.jumpBackward(size);
				painter.turnLeft(45);
				painter.moveForward(size);
			}
			painter.jumpBackward(4*size);
			painter.turnRight(45);
		}
		break; }
	}
	//*/

	SDL_RenderPresent(renderer);
	waitUntilKeyPressed();

	quitSDL(&window, &renderer);

	return 0;
}



