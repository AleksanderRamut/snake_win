#pragma once
#include <deque>
#include "GlobalValues.hpp"
#include "COORD.hpp"
#include "Food.hpp"

class Player
{
public:
    Player();

    void changePosition() noexcept;
    bool checkIfLost() const noexcept;
    bool checkIfFoodEaten() const noexcept;

    std::deque<COORD>& getPlayerRef() noexcept;
    Direction getDirection() const noexcept;
    int getPlayerSize() const noexcept;

    void setDirection(Direction newDirection) noexcept;
    void setPointerToFood(std::shared_ptr<Food>) noexcept;

private:
    std::deque<COORD> player_;
    COORD currentHead_;
    Direction currentDirection_;
    std::shared_ptr<Food> ptrToFood_;
};