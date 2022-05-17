#pragma once
#include <random>
#include "Player.hpp"

class Player;

class Food
{
public:
	Food();

	void changeFoodLocation() noexcept;
	void randomizeFoodLocation() noexcept;
	bool isFoodOnPlayer() const noexcept;

	const COORD& getCurrentLocationRef() const noexcept;

	void setPtrToPlayer_(const std::shared_ptr<Player>& player) noexcept;

private:
	COORD currentLocation_;
    std::shared_ptr<Player> ptrToPlayer_;
	std::random_device rd;
};
