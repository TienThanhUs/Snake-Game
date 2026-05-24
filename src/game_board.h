#pragma once
#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include "snake_entity.h"
#include "food_item.h"
#include "console_printer.h"
#include <iostream>

class GameBoard
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
    GameBoard(const int &w, const int &h);

    void draw();

    bool checkAte();

    void GenerateFood();

    bool GameOver();

    void Sleep(unsigned int milliseconds);

    void Run();
};

#endif
