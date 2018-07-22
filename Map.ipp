template <std::size_t MAP_STRING_LENGTH>
constexpr
Map<MAP_STRING_LENGTH>::Map(const char(&mapString)[MAP_STRING_LENGTH]) :
    m_data(mapString),
    m_width(0),
    m_height(0)
{
    for (std::size_t i = 0; i < MAP_STRING_LENGTH; i++)
    {
	if (mapString[i] == '\n')
	{
	    if (i != 0) // The map string always start by a \n. Ignore it.
	    {
		if (m_width == 0)
		{
		    m_width = i - 1;
		}
		m_height++;
	    }
	}
    }
}


template <std::size_t MAP_STRING_LENGTH>
constexpr char
Map<MAP_STRING_LENGTH>::getPointChar(float x, float y) const
{
    x /= 1000.f;
    y /= 1000.f;
    const unsigned int offset = static_cast<std::size_t>(y) * (m_width + 1) + static_cast<std::size_t>(x) + 1;
    return m_data[offset];
}

template <std::size_t MAP_STRING_LENGTH>
constexpr char
Map<MAP_STRING_LENGTH>::getPointChar(const Vector2f& point) const
{
    return getPointChar(point.X, point.Y);
}


template <std::size_t MAP_STRING_LENGTH>
constexpr std::size_t
Map<MAP_STRING_LENGTH>::width() const
{
    return m_width;
}

template <std::size_t MAP_STRING_LENGTH>
constexpr std::size_t
Map<MAP_STRING_LENGTH>::height() const
{
    return m_height;
}
