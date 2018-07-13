#pragma once

#include "Vector.hpp"

// TODO read the map somewhere.
#define WIDTH	10
#define HEIGHT	10

class	Map
{
public:
    constexpr Map();

    constexpr bool pointIsInsideWall(float x, float y) const;
    constexpr bool pointIsInsideWall(const Vector& point) const;

private:
    const char	m_tiles[HEIGHT][WIDTH + 1];
};

#include "Map.ipp"

