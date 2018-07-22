#pragma once

#include "ConstexprString.hpp"

enum	Color
{
    Black	= 0,
    Red		= 1,
    Green	= 2,
    Yellow	= 3,
    Blue	= 4,
    Magenta	= 5,
    Cyan	= 6,
    White	= 7
};

constexpr auto	GetColorAsConstexprString(Color color);

#include "Color.ipp"
