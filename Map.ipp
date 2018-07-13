constexpr
Map::Map() :
    m_tiles({
#include "map.txt"
	    })
{
}

constexpr bool
Map::pointIsInsideWall(float x, float y) const
{
    x /= 1000.f;
    y /= 1000.f;
    // const unsigned int offset = static_cast<unsigned int>(y * WIDTH) + static_cast<unsigned int>(x);
    return m_tiles[static_cast<unsigned int>(y)][static_cast<unsigned int>(x)] != '0';
}

constexpr bool
Map::pointIsInsideWall(const Vector& point) const
{
    return pointIsInsideWall(point.X, point.Y);
}
