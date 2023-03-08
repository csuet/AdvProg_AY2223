// UPDATE THIS FILE

#include <vector>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include "Game.h"

using namespace std;



// set some attributes as default value
// DO NOT CHANGE THIS CONSTRUCTOR
Game::Game(int _width, int _height)
    : width(_width), height(_height), // play screen
	  squares(_height, vector<CellType>(_width, CELL_EMPTY)), // cell coordinates
      snake(*this, Position(_width/2, _height/2)),  // init snake positin in middle of play screen
      currentDirection(Direction::RIGHT),
      status(GAME_RUNNING),
      score(0)
{
	// add new cheery in game initiation
	addCherry();
}

Game::~Game()
{
    //dtor
}



/***
 * PLEASE UPDATE THIS METHOD
 *
 * When snake moves to a position,
 * if position belongs to BOARD or SNAKE body, status is GAME_OVER
 * if position is having CHERRY :
 * 			- score schoule be increased
 * 			- snake should eat cherry
 * 			- a new cherry should be randomly added
 * otherwise, this position should be assigned as cell of snake
 *
 * Args:
 * 		pos (Position): position where the snake will move
 *
 * Returns:
 * 		// none
 *
***/

void Game::snakeMoveTo(Position pos) {
    CellType posCell = getCellType(pos);
    if (CELL_OFF_BOARD == getCellType(pos) || CELL_SNAKE == getCellType(pos))
    {
        status = GAME_OVER;
    }
    else if (CELL_CHERRY == getCellType(pos))
    {
        score++;
        snake.eatCherry();
        addCherry();
    }
    else
    {
        setCellType(pos, CELL_SNAKE);
    }
}


/***
 * PLEASE UPDATE THIS METHOD
 *
 * When all snake body leave a cell, set it as CELL_EMPTY
 * Args:
 * 		position (Position): position where snake will leave
 * Returns:
 * 		// none
 *
 ***/
void Game::snakeLeave(Position position)
{
	// Suggestion: use setCellType() method in Game class
	setCellType(position, CELL_EMPTY);
}


// DO NOT change this method
void Game::processUserInput(Direction direction)
{
    inputQueue.push(direction);
}


/***
 * PLEASE REPLACE LINES MARKED WITH '// YOUR CODE HERE'
 *
 * check whether the snake can move to the intended direction with the currect direction.
 * If current direction is UP or DOWN, the next direction should not be UP or DOWN
 * if current diection is LEFT or RIGHT, the next direction should not be LEFT or RIGHT
 *
 * Args:
 * 		current (Direction): current direction of the snake
 * 		next (Direction): the intened direction that snake will move
 * Returns:
 * 		bool: whether the snake can ben changed the direction
 *
 ***/
bool Game::canChange(Direction current, Direction next) const {
	if (current == UP || current == DOWN)
		return (next == LEFT || next == RIGHT);
	return (next == UP || next == DOWN);
}


/***
 * PLEASE REPLACE LINES MARKED WITH '// YOUR CODE HERE'
 *
 * Iterover the input queue from keyboard.
 * For each input direction, check whether snake can move or not.
 * If the snake can move,  set currentDiection as this input direction.
 * Otherwise, go to the next input direction from input queue
 *
 * Args:
 * 		// none
 * Returns:
 * 		// none
 *
 ***/

void Game::nextStep()
{
	while (!inputQueue.empty()) {
		// get the input direction from input queue
        Direction next ; // YOUR CODE HERE
        next = inputQueue.front();
		// remove the front of input queue
        // YOUR CODE HERE
        inputQueue.pop();
		// check if snake can move to the next direction, set current direction as next
        if (canChange(currentDirection, next)) {
        	// YOUR CODE HERE
        	currentDirection = next;
        	break;
		}
    }

    snake.move(currentDirection);
}


/***
 * PLEASE REPLACE LINES MARKED WITH '// YOUR CODE HERE'
 *
 * When snake have already eaten a cherry, please add new cherry inside the play screen with random position
 *
 * Args:
 * 		// none
 * Returns:
 * 		// none
 *
 ***/

void Game::addCherry()
{
    do {
		// init a random position inside the play screen (width, height)
		// Suggestion: use rand() function

        Position randomPos(rand() % width, rand() % height); // YOUR CODE HERE

		// check if the randomPos is EMPTY
        if (getCellType(randomPos) == CELL_EMPTY) {

        	// assign the cherry position as randomPos, and set randomPos type as CELL_CHERRY
            cherryPosition = randomPos;
            setCellType(randomPos, CELL_CHERRY);
       		break;
        }
    } while (true);
}


/***
 * PLEASE UPDATE THIS METHOD
 *
 * set cell of a position as intended type.
 *
 * Args:
 * 		pos (Position): a chosen position
 * 		cellType (CellType): cell type of pos
 * Returns:
 * 		// none
 *
 ***/
void Game::setCellType(Position pos, CellType cellType)
{
	// if position is inside the play screen (width, height), set to the cellType.
	// Otherwise, do nothing
	// Suggestion: use pos.isInsideBox(...) in Position class
	if (pos.isInsideBox(0, 0, width, height))
	{
	    squares[pos.y][pos.x] = cellType;
	}
}



// DO NOT change this method
CellType Game::getCellType(Position pos) const
{
	return pos.isInsideBox(0, 0, width, height) ? squares[pos.y][pos.x] : CELL_OFF_BOARD;
}

// DO NOT change this method
vector<Position> Game::getSnakePositions() const
{
    return snake.getPositions();
}

// DO NOT change this method
GameStatus Game::getGameStatus(){
	return status;
}

// DO NOT change this method
int Game::getWidth(){
	return width;
}

// DO NOT change this method
int Game::getHeight(){
	return height;
}

// DO NOT change this method
Snake Game::getSnake(){
	return snake;
}

