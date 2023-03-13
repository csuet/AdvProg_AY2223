
// DO NOT CHANGE THIS FILE
#ifndef POSITION_H
#define POSITION_H

#include <stdexcept>

enum Direction {
    UP = 0, DOWN, LEFT, RIGHT
};

struct Position
{
    int x;
    int y;

    Position(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}

    Position move(Direction direction) const {
    	switch(direction) {
    		case UP: return Position(x, y - 1);
    		case DOWN: return Position(x, y + 1);
    		case LEFT: return Position(x - 1, y);
    		case RIGHT: return Position(x + 1, y);
    		default: throw std::invalid_argument("Unknown direction");
		}
    }

    bool isInsideBox(int left, int top, int width, int height) const {
        return x >= left && x < left+width && y >= top && y < top+height;
    }

    bool operator==(Position p) const {
        return x == p.x && y == p.y;
    }
};

#endif // POSITION_H
