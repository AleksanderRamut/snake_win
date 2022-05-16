#pragma once
#include <iostream>
#include <array>
#include <iomanip>
#include "Player.hpp"

class Player;
class Food;

class Board
{
public:
    Board();

    void draw() noexcept;
    void updateBoard() noexcept;
    void cleanBoard() noexcept;
    void drawFrame() const noexcept;

    void setPtrToFood(std::shared_ptr<Food> ptrToFood) noexcept;
    void setPtrToPlayer(std::shared_ptr<Player> ptrToPlayer) noexcept;

private:
    std::shared_ptr<Player> ptrToPlayer_;
    std::shared_ptr<Food> ptrToFood_;
    std::array<std::array<char, WIDTH>, HEIGHT> board_;
};