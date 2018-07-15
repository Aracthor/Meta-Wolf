#pragma once

template <typename T>
struct	Vector3
{
    constexpr			Vector3();
    constexpr			Vector3(T x, T y, T z);
    constexpr			Vector3(const Vector3<T>& other);

    constexpr void		operator+=(const Vector3<T>& other);
    constexpr void		operator-=(const Vector3<T>& other);
    constexpr void		operator*=(T scale);
    constexpr void		operator/=(T scale);

    constexpr Vector3<T>	operator+(const Vector3<T>& other) const;
    constexpr Vector3<T>	operator-(const Vector3<T>& other) const;
    constexpr Vector3<T>	operator*(T scale) const;
    constexpr Vector3<T>	operator/(T scale) const;

    constexpr bool		operator==(const Vector3<T>& other) const;
    constexpr bool		operator!=(const Vector3<T>& other) const;

    constexpr T			lengthSq() const;
    constexpr T			length() const;

    constexpr void		normalize();

    T				X;
    T				Y;
    T				Z;
};

using Vector3f = Vector3<float>;

#include "Vector3.ipp"
