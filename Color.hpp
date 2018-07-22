#pragma once

#include "ConstexprString.hpp"

namespace Color
{
using Type = char;

constexpr Type Black	= 0;
constexpr Type Red	= 1;
constexpr Type Green	= 2;
constexpr Type Yellow	= 3;
constexpr Type Blue	= 4;
constexpr Type Magenta	= 5;
constexpr Type Cyan	= 6;
constexpr Type White	= 7;

constexpr auto	GetColorAsConstexprString(Type color);

#include "Color.ipp"
}
