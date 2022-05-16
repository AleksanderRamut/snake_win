#pragma once
#include "Board.hpp"

struct COORD
{
    COORD() = default;
    COORD(int X, int Y) : coordX_(X), coordY_(Y)
    {}

    int coordX_;
    int coordY_;
};