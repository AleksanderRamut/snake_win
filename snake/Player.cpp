#include "Player.hpp"

Player::Player() : currentDirection_(Direction::Right), currentHead_(WIDTH/4, HEIGHT/2)
{
    player_.push_back(COORD(WIDTH / 4, HEIGHT / 2));
    player_.push_back(COORD((WIDTH / 4) - 1, HEIGHT / 2));
    player_.push_back(COORD((WIDTH / 4) - 2, HEIGHT / 2));
    player_.push_back(COORD((WIDTH / 4) - 3, HEIGHT / 2));
}

void Player::changePosition() noexcept
{
    switch (static_cast<int>(currentDirection_))
    {
    case 0:
        player_.push_front({ currentHead_.coordX_, currentHead_.coordY_-- });
        if (!checkIfFoodEaten())
        {
            player_.pop_back();
        }
        break;
    case 1:
        player_.push_front({ currentHead_.coordX_, currentHead_.coordY_++ });
        if (!checkIfFoodEaten())
        {
            player_.pop_back();
        }
        break;
    case 2:
        player_.push_front({ currentHead_.coordX_--, currentHead_.coordY_ });
        if (!checkIfFoodEaten())
        {
            player_.pop_back();
        }
        break;
    case 3:
        player_.push_front({ currentHead_.coordX_++, currentHead_.coordY_ });
        if (!checkIfFoodEaten())
        {
            player_.pop_back();
        }
        break;
    }
}
bool Player::checkIfLost() const noexcept
{
    for (auto It = (begin(player_)); It != end(player_); It++)
    {
        if (currentHead_.coordX_ == It->coordX_ && currentHead_.coordY_ == It->coordY_)
        {
            return true;
        }
    }
    if (currentHead_.coordX_ < 0 || currentHead_.coordX_ >= WIDTH || currentHead_.coordY_ < 0 || currentHead_.coordY_ >= HEIGHT)
    {
        return true;
    }
    return false;
}
bool Player::checkIfFoodEaten() const noexcept
{
    if (player_.at(0).coordX_ == ptrToFood_->getCurrentLocationRef().coordX_ && player_.at(0).coordY_ == ptrToFood_->getCurrentLocationRef().coordY_)
    {
        ptrToFood_->changeFoodLocation();
        return true;
    }
    return false;
}

std::deque<COORD>& Player::getPlayerRef()  noexcept
{
    return player_;
}
Direction Player::getDirection() const noexcept
{
    return currentDirection_;
}
int Player::getPlayerSize() const noexcept
{
    return player_.size();
}

void Player::setDirection(Direction newDirection) noexcept
{
    currentDirection_ = newDirection;
}
void Player::setPointerToFood(std::shared_ptr<Food> ptrToFood) noexcept
{
    ptrToFood_ = std::move(ptrToFood);
}
