#ifndef SNAKE_H
#define SNAKE_H

#include <queue>
#include <vector>
#include "Position.h"

using namespace std;

class Game;

struct SnakeNode
{
    Position position;
    SnakeNode *next;
    SnakeNode(Position p, SnakeNode* _next = nullptr) : position(p), next(_next) {}
};

class Snake
{
    SnakeNode *head, *tail;
    Game& game;
    int cherry;
    int score;
public:
    Snake(Game& _game, Position start);
    ~Snake();

    void move(Direction direction);
    bool checkPosition(Position pos);
    vector<Position> getPositions() const;
    void eatCherry();
    int getNumCherry();
    SnakeNode* getTail();
    SnakeNode* getHead();
    void slideTo(Position newPosition);
    void growAtFront(Position newPosition);
};

#endif // SNAKE_H
