#pragma once

// TODO template ?
struct	Vector
{
    constexpr		Vector();
    constexpr		Vector(float x, float y);
    constexpr		Vector(const Vector& other);

    constexpr void	operator+=(const Vector& other);
    constexpr void	operator-=(const Vector& other);
    constexpr void	operator*=(float scale);
    constexpr void	operator/=(float scale);

    constexpr Vector	operator+(const Vector& other) const;
    constexpr Vector	operator-(const Vector& other) const;
    constexpr Vector	operator*(float scale) const;
    constexpr Vector	operator/(float scale) const;

    constexpr bool	operator==(const Vector& other) const;
    constexpr bool	operator!=(const Vector& other) const;

    constexpr float	lengthSq() const;
    constexpr float	length() const;

    constexpr void	normalize();

    float		X;
    float		Y;
};

#include "Vector.ipp"
