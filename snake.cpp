#include "snake.h"
#include "LayKiTu.h"
Snake::Snake(){
    snakeLength = 1;
    dir = STOP;

}
    void Snake::setSnakeX(const int &x, const int &index)
    {
        snakeX[index] = x;
    }
    int Snake::getSnakeX(const int &index)
    {
        return snakeX[index];
    }
    void Snake::setSnakeY(const int &y, const int &index)
    {
        snakeY[index] = y;
    }
    int Snake::getSnakeY(const int &index)
    {
        return snakeY[index];
    }
    void Snake::setSnakeLength()
    {
        snakeLength++;
    }
    int Snake::getSnakeLength()
    {
        return snakeLength;
    }

    void Snake::setDirection()
    {
        if (kbhit())
        {
            switch (getch())
            {
            case 'a':
                dir = LEFT;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'w':
                dir = UP;
                break;
            case 'd':
                dir = RIGHT;
                break;
            }
        }
    }

    void Snake::move()
    {
        // di chuyen tu than truoc
        for (int i = getSnakeLength() - 1; i > 0; i--)
        {
            snakeX[i] = snakeX[i - 1];
            snakeY[i] = snakeY[i - 1];
        }
        switch (dir)
        {
        case LEFT:
        {
            snakeX[0]--;
            break;
        }
        case RIGHT:
        {
            snakeX[0]++;
            break;
        }
        case UP:
        {
            snakeY[0]--;
            break;
        }
        case DOWN:
        {
            snakeY[0]++;
            break;
        }
        case STOP:
            break;
        }
    }