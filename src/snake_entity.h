#pragma once
#ifndef SNAKE_ENTITY_H
#define SNAKE_ENTITY_H

class Snake
{
private:
    int snakeX[1000], snakeY[1000];
    int snakeLength;
    enum eDirection
    {
        STOP = 0,
        LEFT,
        RIGHT,
        UP,
        DOWN
    };
    eDirection dir;

public:
    Snake();

    void setSnakeX(const int &x, const int &index);

    int getSnakeX(const int &index);

    void setSnakeY(const int &y, const int &index);

    int getSnakeY(const int &index);

    void setSnakeLength();

    int getSnakeLength();

    void setDirection();

    void move();
};

#endif
