#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstdlib>
#include <ctime>
#include <thread>
using namespace std;
char getch()
{ // lay ki tu tu ban phim
    char buf = 0;
    struct termios old = {};
    tcgetattr(STDIN_FILENO, &old);
    struct termios newt = old;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    int oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    if (read(STDIN_FILENO, &buf, 1) < 0)
        buf = 0;

    tcsetattr(STDIN_FILENO, TCSANOW, &old);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    return buf;
}
int kbhit()
{ // check neu ban phim dc nhan
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

void space()
{
    for (int i = 0; i < 11; i++)
    {
        cout << endl;
    }
}
void inSo3()
{
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << " ______  \n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << " /      \\ \n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << "/$$$$$$  |\n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << "$$ ___$$ |\n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << "  /   $$< \n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << " _$$$$$  |\n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << "/  \\__$$ |\n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << "$$    $$/ \n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << " $$$$$$/  \n";
}
void inSo2()
{
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << " ______  \n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << " /      \\ \n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << "/$$$$$$  |\n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << "$$____$$ |\n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << " /    $$/ \n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << "/$$$$$$/  \n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << "$$ |_____ \n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << "$$       |\n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << "$$$$$$$$/ \n";
}
void inSo1()
{
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << "  __   \n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << " _/  |  \n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << "/ $$ |  \n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << "$$$$ |  \n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << "  $$ |  \n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << "  $$ |  \n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << " _$$ |_ \n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << "/ $$   |\n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << "$$$$$$/ \n";
}
void inGo()
{
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << "  ______    ______  \n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << " /      \\  /      \\ \n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << "/$$$$$$  |/$$$$$$  |\n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << "$$ | _$$/ $$ |  $$ |\n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << "$$ |/    |$$ |  $$ |\n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << "$$ |$$$$ |$$ |  $$ |\n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << "$$ \\__$$ |$$ \\__$$ |\n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << "$$    $$/ $$    $$/ \n";
    for (int i = 0; i < 75; i++)
    {
        cout << " ";
    }
    cout << " $$$$$$/   $$$$$$/  \n";
}

void printSnake()
{
    cout << "                                ";
    cout << " ______                       __                                                                   \n";
    cout << "                                ";
    cout << " /      \\                     /  |                                                                  \n";
    cout << "                                ";
    cout << "/$$$$$$  | _______    ______  $$ |   __   ______          ______    ______   _____  ____    ______  \n";
    cout << "                                ";
    cout << "$$ \\__$$/ /       \\  /      \\ $$ |  /  | /      \\        /      \\  /      \\ /     \\/    \\  /      \\ \n";
    cout << "                                ";
    cout << "$$      \\ $$$$$$$  | $$$$$$  |$$ |_/$$/ /$$$$$$  |      /$$$$$$  | $$$$$$  |$$$$$$ $$$$  |/$$$$$$  | \n";
    cout << "                                ";
    cout << " $$$$$$  |$$ |  $$ | /    $$ |$$   $$<  $$    $$ |      $$ |  $$ | /    $$ |$$ | $$ | $$ |$$    $$ | \n";
    cout << "                                ";
    cout << "/  \\__$$ |$$ |  $$ |/$$$$$$$ |$$$$$$  \\ $$$$$$$$/       $$ \\__$$ |/$$$$$$$ |$$ | $$ | $$ |$$$$$$$$/ \n";
    cout << "                                ";
    cout << "$$    $$/ $$ |  $$ |$$    $$ |$$ | $$  |$$       |      $$    $$ |$$    $$ |$$ | $$ | $$ |$$       | \n";
    cout << "                                ";
    cout << " $$$$$$/  $$/   $$/  $$$$$$$/ $$/   $$/  $$$$$$$/        $$$$$$$ | $$$$$$$/ $$/  $$/  $$/  $$$$$$$/ \n";
    cout << "                                ";
    cout << "                                                        /  \\__$$ |                                  \n";
    cout << "                                ";
    cout << "                                                        $$    $$/                                   \n";
    cout << "                                ";
    cout << "                                                         $$$$$$/  \n";
}


class Food
{
private:
    int foodX, foodY;

public:
    void setFoodX(const int &tung)
    {
        foodX = tung;
    }
    void setFoodY(const int &hoanh)
    {
        foodY = hoanh;
    }
    int getFoodX()
    {
        return foodX;
    }
    int getFoodY()
    {
        return foodY;
    }
};

/*
chuc nang cua ran chi la di chuyen con an thi o ben board vi no co lien quan den food va food lien quan den board
*/
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
    Snake()
    {
        snakeLength = 1;
        dir = STOP;
    }

    void setSnakeX(const int &x, const int &index)
    {
        snakeX[index] = x;
    }
    int getSnakeX(const int &index)
    {
        return snakeX[index];
    }
    void setSnakeY(const int &y, const int &index)
    {
        snakeY[index] = y;
    }
    int getSnakeY(const int &index)
    {
        return snakeY[index];
    }
    void setSnakeLength()
    {
        snakeLength++;
    }
    int getSnakeLength()
    {
        return snakeLength;
    }

    void setDirection()
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

    void move()
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
};

/*
chuc nang cua board se la ve,quan li viec song chet,tao thuc an,ve bang,setUp
*/
class Board
{
private:
    int streak;
    int score;
    Food food;
    Snake Medusa;
    int witdh;
    int height;
    
    int timeLoss;

public:
    Board(const int &w, const int &h)
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
    
    void draw()
    {

        system("clear");
        printSnake();
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
        { // vien tren
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
                    cout << "\033[1;31m" << "$" << "\033[0m"; // vien trai
                }
                if ((i + 12) == Medusa.getSnakeY(0) && (j + 60) == Medusa.getSnakeX(0))
                { // in ra dau con ran
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
                    cout << "\033[1;31m" << "$" << "\033[0m";
            }
            cout << endl;
            for (int k = 0; k < 60; k++)
            {
                cout << " ";
            }
        }
        for (int i = 0; i < witdh + 2; i++)
        { // vien duoi
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
    bool checkAte()
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
    void GenerateFood()
    {
        int x = (rand() % witdh) + 60;
        int y = (rand() % height) + 12;
        food.setFoodX(x);
        food.setFoodY(y);
        // if(loss.getLossX()==food.getFoodX()&&loss.getLossY()==food.getFoodY()&&streak==6){
        //     return GenerateFood();
        // }
        for (int i = 0; i < Medusa.getSnakeLength(); i++)
        {
            if (Medusa.getSnakeX(i) == food.getFoodX() && Medusa.getSnakeY(i) == food.getFoodY())
            { // neu thuc an trung voi con ran thi generate lai
                GenerateFood();
                break;
            }

        }
    }
    bool GameOver()
    {

        if (Medusa.getSnakeX(0) < 60 || Medusa.getSnakeX(0) > (witdh + 60) || Medusa.getSnakeY(0) < 12 || Medusa.getSnakeY(0) > (height + 12))
        { // neu cham vao vien bang;
            return true;
        }
        for (int i = 1; i < Medusa.getSnakeLength(); i++)
        {
            if (Medusa.getSnakeX(0) == Medusa.getSnakeX(i) && Medusa.getSnakeY(0) == Medusa.getSnakeY(i))
            {
                return true;
            }
        }
        // if (Medusa.getSnakeX(0) == loss.getLossX() && Medusa.getSnakeY(0) == loss.getLossY())
        // {
        //     return true;
        // }
        return false;
    }
    void Sleep(unsigned int milliseconds)
    {
        std::this_thread::sleep_for(std::chrono::microseconds(milliseconds));
    }
    void Run()
    {

        int n = 3;
        do
        {
            system("clear");
            switch (n)
            {
            case 1:
            {
                space();
                inSo1();
                break;
            }
            case 2:
            {
                space();
                inSo2();
                break;
            }
            case 3:
            {
                space();
                inSo3();
                break;
            }
            default:
                break;
            }
            --n;
            this_thread::sleep_for(chrono::seconds(1));

        } while (n);
        system("clear");
        space();
        inGo();
        this_thread::sleep_for(chrono::seconds(1));
        

        do
        {

            draw();
            Medusa.setDirection();
            Medusa.move();
            if (checkAte())
            {
                // if(streak==6&&timeLoss==10){
                //     Generate_Loss();
                // }
                GenerateFood();
                
            }
            if (GameOver())
            {
                cout << "Game over!Final score: " << score << endl;
                break;
            }

            Sleep(100000- Medusa.getSnakeLength() * 100);
        } while (true);
        system("clear");
        for(int i=0;i<25;i++){
            cout<<" ";
        }
        cout << "                                         /$$       /$$                                    \n";
        for(int i=0;i<25;i++){
            cout<<" ";
        }
        cout << "                                        | $$      |__/                                    \n";
        for(int i=0;i<25;i++){
            cout<<" ";
        }
        cout << " /$$$$$$/$$$$   /$$$$$$  /$$   /$$      | $$$$$$$  /$$        /$$$$$$   /$$$$$$  /$$   /$$\n";
        for(int i=0;i<25;i++){
            cout<<" ";
        }
        cout << "| $$_  $$_  $$ |____  $$| $$  | $$      | $$__  $$| $$       /$$__  $$ |____  $$| $$  | $$\n";
        for(int i=0;i<25;i++){
            cout<<" ";
        }
        cout << "| $$ \\ $$ \\ $$  /$$$$$$$| $$  | $$      | $$  \\ $$| $$      | $$  \\ $$  /$$$$$$$| $$  | $$\n";
        for(int i=0;i<25;i++){
            cout<<" ";
        }
        cout << "| $$ | $$ | $$ /$$__  $$| $$  | $$      | $$  | $$| $$      | $$  | $$ /$$__  $$| $$  | $$\n";
        for(int i=0;i<25;i++){
            cout<<" ";
        }
        cout << "| $$ | $$ | $$|  $$$$$$$|  $$$$$$$      | $$$$$$$/| $$      |  $$$$$$$|  $$$$$$$|  $$$$$$$\n";
        for(int i=0;i<25;i++){
            cout<<" ";
        }
        cout << "|__/ |__/ |__/ \\_______/ \\____  $$      |_______/ |__/       \\____  $$ \\_______/ \\____  $$\n";
        for(int i=0;i<25;i++){
            cout<<" ";
        }
        cout << "                         /$$  | $$                           /$$  \\ $$           /$$  | $$\n";
        for(int i=0;i<25;i++){
            cout<<" ";
        }
        cout << "                        |  $$$$$$/                          |  $$$$$$/          |  $$$$$$/\n";
        for(int i=0;i<25;i++){
            cout<<" ";
        }
        cout << "                         \\______/                            \\______/            \\______/  \n";
    }
};

int main()
{
    Board board(32, 18);
    board.Run();
}