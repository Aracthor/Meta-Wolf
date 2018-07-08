#pragma once

#include <array>
#include <ostream>

template <std::size_t N>
class	ConstexprString
{
public:
    constexpr static std::size_t	npos = static_cast<std::size_t>(-1);


private:
    std::array<char, N>	m_data;
    std::size_t		m_size;

public:
    constexpr ConstexprString();
    constexpr ConstexprString(const char* cStr, std::size_t gameStateLength);
    constexpr ConstexprString(const char(&a)[N]);
    template <std::size_t N2>
    constexpr ConstexprString(const char(&a)[N2]);
    template <std::size_t N2>
    constexpr ConstexprString(const std::array<char, N2>& array, std::size_t size);
    template <std::size_t N2>
    constexpr ConstexprString(const ConstexprString<N2>& other);

    constexpr const char*	begin() const;
    constexpr const char*	end() const;

    constexpr std::size_t	indexOf(char c, std::size_t start = 0) const;
    constexpr ConstexprString<N>substr(std::size_t index, std::size_t size) const;

    constexpr char		operator[](unsigned int index) const;
    constexpr char&		operator[](unsigned int index);

    constexpr const char*	data() const;
    constexpr std::size_t	size() const;
    constexpr void		resize(unsigned int newSize);

    constexpr ConstexprString<N + 1>	operator+(char c) const;
    template <std::size_t N2>
    constexpr ConstexprString<N + N2>	operator+(const char(&a)[N2]) const;
    template <std::size_t N2>
    constexpr ConstexprString<N + N2>	operator+(const ConstexprString<N2>& other) const;

    constexpr std::size_t	asNumber() const;

private:
    void	checkForNulCharacter();
};

template <typename T>
constexpr ConstexprString<sizeof(T)> CreateConstexprString(const T& data);

constexpr ConstexprString<1> CreateConstexprStringFromChar(char c);

constexpr ConstexprString<10> CreateConstexprStringFromInt(unsigned int number);

template <std::size_t N>
std::ostream&	operator<<(std::ostream& stream, const ConstexprString<N>& string);

#include "ConstexprString.ipp"
