#pragma once

template <typename T>
struct	Vector2
{
    constexpr			Vector2();
    constexpr			Vector2(T x, T y);
    constexpr			Vector2(const Vector2<T>& other);

    constexpr void		operator+=(const Vector2<T>& other);
    constexpr void		operator-=(const Vector2<T>& other);
    constexpr void		operator*=(T scale);
    constexpr void		operator/=(T scale);

    constexpr Vector2<T>	operator+(const Vector2<T>& other) const;
    constexpr Vector2<T>	operator-(const Vector2<T>& other) const;
    constexpr Vector2<T>	operator*(T scale) const;
    constexpr Vector2<T>	operator/(T scale) const;

    constexpr bool		operator==(const Vector2<T>& other) const;
    constexpr bool		operator!=(const Vector2<T>& other) const;

    constexpr T			lengthSq() const;
    constexpr T			length() const;

    constexpr void		normalize();

    T				X;
    T				Y;
};

using Vector2f = Vector2<float>;

#include "Vector2.ipp"
