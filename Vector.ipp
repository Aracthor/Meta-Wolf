#include "Maths.hpp"

constexpr
Vector::Vector() :
    X(0.f),
    Y(0.f)
{
}

constexpr
Vector::Vector(float x, float y) :
    X(x),
    Y(y)
{
}

constexpr
Vector::Vector(const Vector& other) :
    X(other.X),
    Y(other.Y)
{
}


constexpr void
Vector::operator+=(const Vector& other)
{
    X += other.X;
    Y += other.Y;
}

constexpr void
Vector::operator-=(const Vector& other)
{
    X -= other.X;
    Y -= other.Y;
}

constexpr void
Vector::operator*=(float scale)
{
    X *= scale;
    Y *= scale;
}

constexpr void
Vector::operator/=(float scale)
{
    X /= scale;
    Y /= scale;
}


constexpr Vector
Vector::operator+(const Vector& other) const
{
    return Vector(X + other.X, Y + other.Y);
}

constexpr Vector
Vector::operator-(const Vector& other) const
{
    return Vector(X - other.X, Y - other.Y);
}

constexpr Vector
Vector::operator*(float scale) const
{
    return Vector(X * scale, Y * scale);
}

constexpr Vector
Vector::operator/(float scale) const
{
    return Vector(X / scale, Y / scale);
}


constexpr bool
Vector::operator==(const Vector& other) const
{
    return X == other.X && Y == other.Y;
}

constexpr bool
Vector::operator!=(const Vector& other) const
{
    return !operator==(other);
}


constexpr float
Vector::lengthSq() const
{
    return X * X + Y * Y;
}

constexpr float
Vector::length() const
{
    return Maths::sqrt(lengthSq());
}


constexpr void
Vector::normalize()
{
    const float vectorLength = length();

    X /= vectorLength;
    Y /= vectorLength;
}
