#include "game_board.h"

#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fcntl.h>
#include <termios.h>
#include <thread>
#include <unistd.h>

using namespace std;

GameBoard::GameBoard(const int &w, const int &h)
{
    timeLoss = 10;
    streak = 0;
    witdh = w;
    height = h;
    score = 0;
    food.setFoodX((rand() % w) + 60);
    food.setFoodY((rand() % h) + 12);
    Medusa.setSnakeX((w / 2) + 60, 0);
    Medusa.setSnakeY((h / 2) + 12, 0);
}

void GameBoard::draw()
{
    system("clear");
    in.printSnake();

    for (int k = 0; k < 75; k++)
    {
        cout << " ";
    }
    cout << "Score:" << score << endl;

    for (int k = 0; k < 60; k++)
    {
        cout << " ";
    }
    for (int i = 0; i < witdh + 2; i++)
    {
        cout << "\033[1;31m" << "$" << "\033[0m";
    }
    cout << endl;

    for (int k = 0; k < 60; k++)
    {
        cout << " ";
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < witdh; j++)
        {
            if (!j)
            {
                cout << "\033[1;31m" << "$" << "\033[0m";
            }

            if ((i + 12) == Medusa.getSnakeY(0) && (j + 60) == Medusa.getSnakeX(0))
            {
                cout << "\033[1;32m" << "O" << "\033[0m";
            }
            else if ((i + 12) == food.getFoodY() && (j + 60) == food.getFoodX())
            {
                cout << "\033[1;31m" << "o" << "\033[0m";
            }
            else
            {
                bool check = false;
                for (int k = 1; k < Medusa.getSnakeLength(); k++)
                {
                    if (Medusa.getSnakeX(k) == (j + 60) && Medusa.getSnakeY(k) == (i + 12))
                    {
                        cout << "\033[1;32m" << "o" << "\033[0m";
                        check = true;
                    }
                }
                if (!check)
                {
                    cout << " ";
                }
            }

            if (j == witdh - 1)
            {
                cout << "\033[1;31m" << "$" << "\033[0m";
            }
        }

        cout << endl;
        for (int k = 0; k < 60; k++)
        {
            cout << " ";
        }
    }

    for (int i = 0; i < witdh + 2; i++)
    {
        cout << "\033[1;31m" << "$" << "\033[0m";
    }
    cout << endl;

    for (int k = 0; k < 60; k++)
    {
        cout << " ";
    }
    cout << endl;
    cout << "                       ";
    cout << "\033[1;32m" << " _   _  _____ _    ___     ________ _   _    _______ _____ ______ _   _     _______ _    _          _   _ _    _ " << "\033[0m" << endl;
    cout << "                       ";
    cout << "\033[1;32m" << " | \\ | |/ ____| |  | \\ \\   / /  ____| \\ | |  |__   __|_   _|  ____| \\ | |   |__   __| |  | |   /\\   | \\ | | |  | |" << "\033[0m" << endl;
    cout << "                       ";
    cout << "\033[1;32m" << " |  \\| | |  __| |  | |\\ \\_/ /| |__  |  \\| |     | |    | | | |__  |  \\| |      | |  | |__| |  /  \\  |  \\| | |__| |" << "\033[0m" << endl;
    cout << "                       ";
    cout << "\033[1;32m" << " | . ` | | |_ | |  | | \\   / |  __| | . ` |     | |    | | |  __| | . ` |      | |  |  __  | / /\\ \\ | . ` |  __  |" << "\033[0m" << endl;
    cout << "                       ";
    cout << "\033[1;32m" << " | |\\  | |__| | |__| |  | |  | |____| |\\  |     | |   _| |_| |____| |\\  |      | |  | |  | |/ ____ \\| |\\  | |  | |" << "\033[0m" << endl;
    cout << "                       ";
    cout << "\033[1;32m" << " |_| \\_|\\_____|\\____/   |_|  |______|_| \\_|     |_|  |_____|______|_| \\_|      |_|  |_|  |_/_/    \\_\\_| \\_|_|  |_|" << "\033[0m" << endl;
}

bool GameBoard::checkAte()
{
    if (Medusa.getSnakeX(0) == food.getFoodX() && Medusa.getSnakeY(0) == food.getFoodY())
    {
        Medusa.setSnakeLength();
        score += 10;
        streak++;
        return true;
    }
    return false;
}

void GameBoard::GenerateFood()
{
    int x = (rand() % witdh) + 60;
    int y = (rand() % height) + 12;
    food.setFoodX(x);
    food.setFoodY(y);

    for (int i = 0; i < Medusa.getSnakeLength(); i++)
    {
        if (Medusa.getSnakeX(i) == food.getFoodX() && Medusa.getSnakeY(i) == food.getFoodY())
        {
            GenerateFood();
            break;
        }
    }
}

bool GameBoard::GameOver()
{
    if (Medusa.getSnakeX(0) < 60 || Medusa.getSnakeX(0) > (witdh + 60) || Medusa.getSnakeY(0) < 12 || Medusa.getSnakeY(0) > (height + 12))
    {
        return true;
    }

    for (int i = 1; i < Medusa.getSnakeLength(); i++)
    {
        if (Medusa.getSnakeX(0) == Medusa.getSnakeX(i) && Medusa.getSnakeY(0) == Medusa.getSnakeY(i))
        {
            return true;
        }
    }

    return false;
}

void GameBoard::Sleep(unsigned int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::microseconds(milliseconds));
}

void GameBoard::Run()
{
    int n = 3;
    do
    {
        system("clear");
        switch (n)
        {
        case 1:
        {
            in.space();
            in.inSo1();
            break;
        }
        case 2:
        {
            in.space();
            in.inSo2();
            break;
        }
        case 3:
        {
            in.space();
            in.inSo3();
            break;
        }
        default:
            break;
        }
        --n;
        this_thread::sleep_for(chrono::seconds(1));
    } while (n);

    system("clear");
    in.space();
    in.inGo();
    this_thread::sleep_for(chrono::seconds(1));

    do
    {
        draw();
        Medusa.setDirection();
        Medusa.move();
        if (checkAte())
        {
            GenerateFood();
        }
        if (GameOver())
        {
            cout << "Game over!Final score: " << score << endl;
            break;
        }

        Sleep(100000 - Medusa.getSnakeLength() * 250);
    } while (true);
}
