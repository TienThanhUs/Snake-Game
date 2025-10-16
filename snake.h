#pragma once
#ifndef SNAKE_H
#define SNAKE_H

class Snake
{ // chi nen tao cac thuoc tinh cua no nhu 1 con ran binh thuong chu ko nen kiem tra cac cai an hay ko
private:
    int snakeX[1000], snakeY[1000]; // toa do cac phan cua con ran
    int snakeLength;
    enum eDirection
    {
        STOP = 0,
        LEFT,
        RIGHT,
        UP,
        DOWN
    }; // cac huong cua con ran
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