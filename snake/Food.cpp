#include "Food.hpp"

Food::Food()
{
    randomizeFoodLocation();
}

void Food::changeFoodLocation() noexcept
{
    do
    {
        randomizeFoodLocation();
    } while (isFoodOnPlayer());
}
void Food::randomizeFoodLocation() noexcept
{
    std::mt19937 rng(rd());
    std::uniform_int_distribution<> distrib(0, WIDTH - 1);
    currentLocation_.coordX_ = distrib(rng);
    distrib = std::uniform_int_distribution<>(0, HEIGHT - 1);
    currentLocation_.coordY_ = distrib(rng);
}
bool Food::isFoodOnPlayer() const noexcept
{
    for (const auto& el : ptrToPlayer_->getPlayerRef())
    {
        if (currentLocation_.coordX_ == el.coordX_ && currentLocation_.coordY_ == el.coordY_)
        {
            return true;
        }
    }
    return false;
}

const COORD& Food::getCurrentLocationRef() const noexcept
{
    return currentLocation_;
}

void Food::setPtrToPlayer_(const std::shared_ptr<Player>& ptrToPlayer) noexcept
{
    ptrToPlayer_ = ptrToPlayer;
}
