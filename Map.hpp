#pragma once

#include "Vector2.hpp"

template <std::size_t MAP_STRING_LENGTH>
class	Map
{
public:
    constexpr Map(const char(&mapString)[MAP_STRING_LENGTH]);

    constexpr char getPointChar(float x, float y) const;
    constexpr char getPointChar(const Vector2f& point) const;

    constexpr std::size_t	width() const;
    constexpr std::size_t	height() const;

private:
    const char*	m_data;
    std::size_t	m_width;
    std::size_t	m_height;
};

#include "Map.ipp"

