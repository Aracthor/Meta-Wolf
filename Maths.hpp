#pragma once

namespace Maths
{
constexpr float _PI = 3.14159265359;
constexpr float _PI_2 = _PI / 2.f;
constexpr float _2_PI = 2.f * _PI;

template <typename T>
constexpr T		pow(T number, unsigned int n);
constexpr unsigned int	fact(unsigned int n);

constexpr float	sqrt(float n);

constexpr float	degToRad(float angle);
constexpr float	cos(float angle);
constexpr float	sin(float angle);
} // namespace Maths

#include "Maths.ipp"
