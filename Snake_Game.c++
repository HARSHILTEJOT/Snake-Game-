#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;

class SnakeGame {
private:
    bool gameOver;
    const int width = 50, height = 25; // Updated grid size
    int x, y, score;
    int tailX[100], tailY[100];
    int nTail = 2;
    int fruitX[4], fruitY[4]; // Store multiple food positions
    int speed;
    enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
    eDirection dir;

    void gotoxy(int x, int y) 
    {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

    void hideCursor()
    {
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        cursorInfo.bVisible = false;
        cursorInfo.dwSize = 1;
        SetConsoleCursorInfo(consoleHandle, &cursorInfo);
    }

    void draw() 
    {
        gotoxy(0, 0);
        for (int i = 0; i < height; i++) 
        {
            cout << "#";
            for (int j = 0; j < width - 2; j++) 
            {
                if (i == 0 || i == height - 1) 
                {
                    cout << "#";
                }
                else if (i == y && j == x) cout << "O";
                else 
                {
                    bool print = false;
                    for (int k = 0; k < nTail; k++) 
                    {
                        if (tailX[k] == j && tailY[k] == i) 
                        {
                            cout << "o";
                            print = true;
                        }
                    }
                    for (int f = 0; f < 4; f++) 
                    {
                        if (fruitX[f] == j && fruitY[f] == i) 
                        {
                            cout << "F";
                            print = true;
                        }
                    }
                    if (!print) cout << " ";
                }
            }
            cout << "#" << endl;
        }
        cout << "Score : " << score;
    }

    void input() 
    {
        if (_kbhit()) 
        {
            switch (_getch()) 
            {
                case 'w': dir = UP; break;
                case 's': dir = DOWN; break;
                case 'a': dir = LEFT; break;
                case 'd': dir = RIGHT; break;
                case 'x': gameOver = true; break;
            }
        }
    }

    void logic() 
    {
        int prevX = tailX[0], prevY = tailY[0], prev2X, prev2Y;
        tailX[0] = x;
        tailY[0] = y;
        for (int i = 1; i < nTail; i++) 
        {
            prev2X = tailX[i];
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }
        switch (dir) 
        {
            case UP: y--; break;
            case DOWN: y++; break;
            case LEFT: x--; break;
            case RIGHT: x++; break;
            default: break;
        }
        if (x == width - 1 || x == 0 || y == height - 1 || y == 0) gameOver = true;
        for (int i = 0; i < nTail; i++) 
        {
            if (tailX[i] == x && tailY[i] == y) gameOver = true;
        }
        for (int f = 0; f < 4; f++)
        {
            if (x == fruitX[f] && y == fruitY[f]) 
            {
                score += 10;
                fruitX[f] = rand() % (width - 2) + 1;
                fruitY[f] = rand() % (height - 2) + 1;
                nTail++;
            }
        }
    }

    void gameOverScreen() 
    {
         system("cls");
        gotoxy(width / 4, height / 3);
        cout << "" << endl;
        gotoxy(width / 4, (height / 3) + 1);
        cout << "*        GAME OVER       *" << endl;
        gotoxy(width / 4, (height / 3) + 2);
        cout << "" << endl;
        gotoxy(width / 4, (height / 3) + 4);
        cout << "Final Score: " << score << endl;
        gotoxy(width / 4, (height / 3) + 6);
        cout << "Press any key to exit...";
        _getch();
    }

    void selectDifficulty()
    {
        int choice;
        cout << "Select Difficulty Level:\n1. Easy\n2. Medium\n3. Hard\n";
        cin >> choice;
        switch (choice)
        {
            case 1: speed = 75; cout << "Level: Easy\n"; break;
            case 2: speed = 50; cout << "Level: Medium\n"; break;
            case 3: speed = 10; cout << "Level: Hard\n"; break;
            default: speed = 100; cout << "Defaulting to Easy\n"; break;
        }
    }

public:
    SnakeGame() 
    {
        srand(time(0));
        gameOver = false;
        dir = RIGHT;
        x = width / 2;
        y = height / 2;
        selectDifficulty();
        hideCursor();
        for (int i = 0; i < 4; i++) 
        {
            fruitX[i] = rand() % (width - 2) + 1;
            fruitY[i] = rand() % (height - 2) + 1;
        }
        for (int i = 0; i < nTail; i++) 
        {
            tailX[i] = x - (i + 1);
            tailY[i] = y;
        }
        score = 0;
    }

    void run() 
    {
        while (!gameOver) 
        {
            draw();
            input();
            logic();
            Sleep(speed);
        }
        gameOverScreen();
    }
};

int main() 
{
    system("cls");
    SnakeGame game;
    game.run();
    return 0;
}
