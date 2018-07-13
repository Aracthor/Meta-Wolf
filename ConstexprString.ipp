#include "Maths.hpp"

template <std::size_t N>
constexpr
ConstexprString<N>::ConstexprString() :
    m_data(),
    m_size(0)
{
}

template <std::size_t N>
constexpr
ConstexprString<N>::ConstexprString(const char* cStr, std::size_t strLength) :
    m_data(),
    m_size(strLength)
{
    for (unsigned int i = 0; i < strLength; i++)
    {
	m_data[i] = cStr[i];
    }
}

template <std::size_t N>
constexpr ConstexprString<N>::ConstexprString(const char(&a)[N]) :
    m_data({}),
    m_size(N)
{
    for (unsigned int i = 0; i < N; i++)
    {
	m_data[i] = a[i];
    }
    checkForNulCharacter();
}

template <std::size_t N>
template <std::size_t N2>
constexpr ConstexprString<N>::ConstexprString(const char(&a)[N2]) :
    m_data({}),
    m_size(N2)
{
    for (unsigned int i = 0; i < N2; i++)
    {
	m_data[i] = a[i];
    }
    checkForNulCharacter();
}

template <std::size_t N>
template <std::size_t N2>
constexpr ConstexprString<N>::ConstexprString(const std::array<char, N2>& array, std::size_t size) :
    m_data({}),
    m_size(size)
{
    for (unsigned int i = 0; i < size; i++)
    {
	m_data[i] = array[i];
    }
}

template <std::size_t N>
template <std::size_t N2>
constexpr ConstexprString<N>::ConstexprString(const ConstexprString<N2>& other) :
    ConstexprString<N>(other.data(), other.size())
{
}


template <std::size_t N>
constexpr const char* ConstexprString<N>::begin() const
{
    return m_data.data();
}

template <std::size_t N>
constexpr const char* ConstexprString<N>::end() const
{
    return m_data.data() + m_size;
}


template <std::size_t N>
constexpr std::size_t
ConstexprString<N>::indexOf(char c, std::size_t start /* = 0*/) const
{
    std::size_t	index = start;

    while (index < m_size && m_data[index] != c)
	index++;

    if (index == m_size)
	index = npos;

    return index;
}

template <std::size_t N>
constexpr ConstexprString<N>
ConstexprString<N>::substr(std::size_t index, std::size_t size) const
{
    ConstexprString<N>	result;

    result.resize(size);
    for (std::size_t i = 0; i < size; i++)
    {
	result[i] = m_data[i + index];
    }

    return result;
}


template <std::size_t N>
constexpr char
ConstexprString<N>::operator[](unsigned int index) const
{
    return m_data[index];
}

template <std::size_t N>
constexpr char&
ConstexprString<N>::operator[](unsigned int index)
{
    return m_data[index];
}


template <std::size_t N>
constexpr const char*
ConstexprString<N>::data() const
{
    return m_data.data();
}

template <std::size_t N>
constexpr std::size_t
ConstexprString<N>::size() const
{
    return m_size;
}

template <std::size_t N>
constexpr void
ConstexprString<N>::resize(unsigned int newSize)
{
    m_size = newSize;
}


template <std::size_t N>
constexpr ConstexprString<N + 1>
ConstexprString<N>::operator+(char c) const
{
    ConstexprString<N + 1> newString = ConstexprString<N + 1>(*this);
    newString.resize(m_size + 1);
    newString[m_size] = c;
    return newString;
}

template <std::size_t N>
template <std::size_t N2>
constexpr ConstexprString<N + N2>
ConstexprString<N>::operator+(const ConstexprString<N2>& other) const
{
    ConstexprString<N + N2>	result(*this);

    for (unsigned int i = 0; i < other.size(); i++)
    {
	result[m_size + i] = other[i];
    }
    result.resize(m_size + other.size());

    return result;
}

template <std::size_t N>
template <std::size_t N2>
constexpr ConstexprString<N + N2>
ConstexprString<N>::operator+(const char(&a)[N2]) const
{
    ConstexprString<N + N2>	result(*this);

    for (unsigned int i = 0; i < N2; i++)
    {
	result[m_size + i] = a[i];
    }
    result.resize(m_size + N2);

    return result;
}


template <std::size_t N>
constexpr std::size_t
ConstexprString<N>::asNumber() const
{
    std::size_t result = 0;
    std::size_t	index = 0;

    while (index < m_size)
    {
	result *= 10;
	result += m_data[index] - '0';
	index++;
    }

    return result;
}


template <typename T>
constexpr ConstexprString<sizeof(T)>
CreateConstexprString(const T& data)
{
    return ConstexprString<sizeof(T)>(data);
}

constexpr ConstexprString<1>
CreateConstexprStringFromChar(char c)
{
    ConstexprString<1>	result("");

    result[0] = c;
    result.resize(1);
    return result;
}

constexpr ConstexprString<10>
CreateConstexprStringFromInt(unsigned int number)
{
    ConstexprString<10>	result;

    if (number == 0)
    {
	result[0] = '0';
	result.resize(1);
    }
    else
    {
	unsigned int	digits = 0;
	unsigned int	copy = number;
	unsigned int	i = 0;

	while (copy > 0)
	{
	    digits++;
	    copy /= 10;
	}
	result.resize(digits);
	while (digits > 0)
	{
	    unsigned int	power = Maths::pow(10, digits - 1);
	    result[i++] = number / power + '0';
	    number %= power;
	    digits--;
	}
    }

    return result;
}


template <std::size_t N>
constexpr void
ConstexprString<N>::checkForNulCharacter()
{
    if (m_data[m_size - 1] == '\0')
	m_size--;
}


template <std::size_t N>
std::ostream&	operator<<(std::ostream& stream, const ConstexprString<N>& string)
{
    for (const char c : string)
    {
	stream << c;
    }
    return stream;
}
