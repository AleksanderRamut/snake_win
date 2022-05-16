#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
#include "Food.hpp"

void startScreen();
void endScreen();

int main()
{
    startScreen();

    auto player = std::make_shared<Player>();
    auto food = std::make_shared<Food>();
    auto board = std::make_shared<Board>();

    player->setPointerToFood(food);
    food->setPtrToPlayer_(player);
    board->setPtrToFood(food);
    board->setPtrToPlayer(player);

    while (true)
    {
        if (_kbhit())
        {
            switch (_getch())
            {
            case 'w':
                if (player->getDirection() != Direction::Down)
                {
                    player->setDirection(Direction::Up);
                }
                break;
            case 's':
                if (player->getDirection() != Direction::Up)
                {
                    player->setDirection(Direction::Down);
                }
                break;
            case 'a':
                if (player->getDirection() != Direction::Right)
                {
                    player->setDirection(Direction::Left);
                }
                break;
            case 'd':
                if (player->getDirection() != Direction::Left)
                {
                    player->setDirection(Direction::Right);
                }
                break;
            case 'q':
                exit(0);
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(SPEED));
        player->changePosition();
        if (player->checkIfLost())
        {
            board->draw();
            endScreen();
        }
        board->draw();
    }
}

void startScreen()
{
    std::cout << "PYTHON" << std::endl;
    std::cout << "Instructions: wasd to change direction, q to escape" << std::endl;
    std::cout << "Press any button to start..." << std::endl;
    _getch();
}

void endScreen()
{
    std::cout << "YOU LOSE!!!" << std::endl;
    std::cout << "Press q to escape..." << std::endl;
    while(_getch() != 'q')
    { }
    exit(0);
}
