#pragma once
#ifndef BOARD_H
#define BOARD_H
#include "snake.h"
#include "food.h"
#include "in.h"
#include<iostream>
using namespace std;
class Board
{
private:
    Print in;
    int streak;
    int score;
    Food food;
    Snake Medusa;
    int witdh;
    int height;
    
    int timeLoss;

public:
    Board(const int &w, const int &h);
    
    
    void draw();
   
    bool checkAte();
    
    void GenerateFood();
    
    bool GameOver();
    
    void Sleep(unsigned int milliseconds);
   
    void Run();
    
};

#endif