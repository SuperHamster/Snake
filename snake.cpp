#include "snake.h"

snake::snake()
{
    snakeNode snakeHead;
    snakeHead.iCurrentPosition = 1;
    snakeHead.jCurrentPosition = 1;
    _snake.push_back(snakeHead);
    snakeLength = 1;
}

void snake::snakeMove()
{
    if (snakeLength > 1)
        for (int i = snakeLength - 1; i > 0; i--)
        {
            _snake[i].iCurrentPosition = _snake[i - 1].iCurrentPosition;
            _snake[i].jCurrentPosition = _snake[i - 1].jCurrentPosition;
        }
}

bool snake::snakeMoving(int keyButton, field myField)
{
    if ((keyButton == moveUp && currentDirection != direction::DOWN) ||
        (currentDirection == direction::UP && keyButton != moveRight && keyButton != moveLeft))
    {
        if (_snake[0].iCurrentPosition - 1 < 0)
        {
            snakeMove();

            _snake[0].iCurrentPosition = myField.fieldLength - 1;
            currentDirection = direction::UP;
        }
        else if (myField._field[_snake[0].iCurrentPosition - 1][_snake[0].jCurrentPosition] == cell::BLANK)
        {
            snakeMove();

            _snake[0].iCurrentPosition--;
            currentDirection = direction::UP;
        }
        else if (myField._field[_snake[0].iCurrentPosition - 1][_snake[0].jCurrentPosition] == cell::FOOD)
        {
            snakeMove();

            snakeNode _snakeNode;
            _snakeNode.iCurrentPosition = _snake[snakeLength - 1].iCurrentPosition;
            _snakeNode.jCurrentPosition = _snake[snakeLength - 1].jCurrentPosition;
            _snake.push_back(_snakeNode);

            snakeLength++;
            _snake[0].iCurrentPosition--;
            points += 10;

            if (waitTime > 20)
                waitTime--;

            isSnakeEatTheFood = 1;

            currentDirection = direction::UP;
        }
        else
            return 0;
    } else if (keyButton == moveUp && currentDirection == direction::DOWN)
        currentDirection = direction::DOWN;


    if ((keyButton == moveDown && currentDirection != direction::UP) ||
        (currentDirection == direction::DOWN && keyButton != moveRight && keyButton != moveLeft))
    {
        if (_snake[0].iCurrentPosition + 1 > myField.fieldLength - 1)
        {
            snakeMove();

            _snake[0].iCurrentPosition = 0;
            currentDirection = direction::DOWN;
        }
        else if (myField._field[_snake[0].iCurrentPosition + 1][_snake[0].jCurrentPosition] == cell::BLANK)
        {
            snakeMove();

            _snake[0].iCurrentPosition++;
            currentDirection = direction::DOWN;
        }
        else if (myField._field[_snake[0].iCurrentPosition + 1][_snake[0].jCurrentPosition] == cell::FOOD)
        {
            snakeMove();

            snakeNode _snakeNode;
            _snakeNode.iCurrentPosition = _snake[snakeLength - 1].iCurrentPosition;
            _snakeNode.jCurrentPosition = _snake[snakeLength - 1].jCurrentPosition;
            _snake.push_back(_snakeNode);

            snakeLength++;
            _snake[0].iCurrentPosition++;
            points += 10;

            if (waitTime > 20)
                waitTime--;

            isSnakeEatTheFood = 1;

            currentDirection = direction::DOWN;
        }
        else
            return 0;
    } else if (keyButton == moveDown && currentDirection == direction::UP)
        currentDirection = direction::UP;


    if ((keyButton == moveLeft || currentDirection == direction::LEFT)  && currentDirection != direction::RIGHT)
    {
        if (_snake[0].jCurrentPosition - 1 < 0)
        {
            snakeMove();

            _snake[0].jCurrentPosition = myField.fieldWidth - 1;
            currentDirection = direction::LEFT;
        }
        else if (myField._field[_snake[0].iCurrentPosition][_snake[0].jCurrentPosition - 1] == cell::BLANK)
        {
            snakeMove();

            _snake[0].jCurrentPosition--;
            currentDirection = direction::LEFT;
        }
        else if (myField._field[_snake[0].iCurrentPosition][_snake[0].jCurrentPosition - 1] == cell::FOOD)
        {
            snakeMove();
            snakeNode _snakeNode;
            _snakeNode.iCurrentPosition = _snake[snakeLength - 1].iCurrentPosition;
            _snakeNode.jCurrentPosition = _snake[snakeLength - 1].jCurrentPosition;
            _snake.push_back(_snakeNode);

            snakeLength++;
            _snake[0].jCurrentPosition--;
            points += 10;

            if (waitTime > 20)
                waitTime--;

            isSnakeEatTheFood = 1;

            currentDirection = direction::LEFT;
        }
        else
            return 0;
    } else if (keyButton == moveLeft && currentDirection == direction::RIGHT)
        currentDirection = direction::RIGHT;


    if ((keyButton == moveRight || currentDirection == direction::RIGHT) && currentDirection != direction::LEFT)
    {
        if (_snake[0].jCurrentPosition + 1 > myField.fieldWidth - 1)
        {
            snakeMove();

            _snake[0].jCurrentPosition = 0;
            currentDirection = direction::RIGHT;
        }
        else if (myField._field[_snake[0].iCurrentPosition][_snake[0].jCurrentPosition + 1] == cell::BLANK)
        {
            snakeMove();

            _snake[0].jCurrentPosition++;
            currentDirection = direction::RIGHT;
        }
        else if (myField._field[_snake[0].iCurrentPosition][_snake[0].jCurrentPosition + 1] == cell::FOOD)
        {
            snakeMove();
            snakeNode _snakeNode;
            _snakeNode.iCurrentPosition = _snake[snakeLength - 1].iCurrentPosition;
            _snakeNode.jCurrentPosition = _snake[snakeLength - 1].jCurrentPosition;
            _snake.push_back(_snakeNode);

            snakeLength++;
            _snake[0].jCurrentPosition++;
            points += 10;

            if (waitTime > 20)
                waitTime--;

            isSnakeEatTheFood = 1;

            currentDirection = direction::RIGHT;
        }
        else
            return 0;
    } else if (keyButton == moveRight && currentDirection == direction::LEFT)
        currentDirection = direction::LEFT;

    return 1;
}


snake::~snake()
{}


























