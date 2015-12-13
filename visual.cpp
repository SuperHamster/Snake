#include "visual.h"
//#include <ncurses.h>
#include <conio.h>
#include <iostream>

visual::visual()
{
    consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
}

void visual::gameConsoleOut(snake mySnake, field myField)
{
    COORD cursorCoord;
    cursorCoord.X = 0;
    cursorCoord.Y = 0;
    SetConsoleCursorPosition(consoleHandle,cursorCoord);

    std::cout << "Your points: " << mySnake.points << std::endl;

    for (int i = 0; i < myField.fieldLength; i++)
    {
        for (int j = 0; j < myField.fieldWidth; j++)
            switch (myField._field[i][j]){
            case  WALL:
                std::cout << "#";
                break;
            case  BLANK:
                std::cout << " ";
                break;
            case  SNAKE:
                std::cout << "o";
                break;
            case  SNAKE_HEAD:
                std::cout << "O";
                break;
            case  SNAKE_TALE:
                std::cout << ".";
                break;
            case  FOOD:
                std::cout << "*";
                break;
            }
        std::cout << std::endl;
    }
}

void visual::gameOverScreen(snake mySnake)
{
    system ("cls");

    std::cout << "Game Over\nTotal points: " << mySnake.points << std::endl;
}

visual::~visual()
{}
