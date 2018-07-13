#pragma once

#include "ConstexprString.hpp"

namespace Keyboard
{
enum Key
{
    Front,
    Back,
    Right,
    Left,
    Escape,
    Invalid
};

constexpr Key GetKeyPressed();

template <Keyboard::Key key>
constexpr auto	GetKeyAsConstexprString();


#include "Keyboard.ipp"
}
