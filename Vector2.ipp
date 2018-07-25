#include "Maths.hpp"

template <typename T>
constexpr T
Vector2<T>::dot(const Vector2<T>& u, const Vector2<T>& v)
{
    return (u.x * v.x + u.y * v.y);
}


template <typename T>
constexpr
Vector2<T>::Vector2() :
    X(0.f),
    Y(0.f)
{
}

template <typename T>
constexpr
Vector2<T>::Vector2(T x, T y) :
    X(x),
    Y(y)
{
}

template <typename T>
constexpr
Vector2<T>::Vector2(const Vector2<T>& other) :
    X(other.X),
    Y(other.Y)
{
}


template <typename T>
constexpr void
Vector2<T>::operator+=(const Vector2<T>& other)
{
    X += other.X;
    Y += other.Y;
}

template <typename T>
constexpr void
Vector2<T>::operator-=(const Vector2<T>& other)
{
    X -= other.X;
    Y -= other.Y;
}

template <typename T>
constexpr void
Vector2<T>::operator*=(T scale)
{
    X *= scale;
    Y *= scale;
}

template <typename T>
constexpr void
Vector2<T>::operator/=(T scale)
{
    X /= scale;
    Y /= scale;
}


template <typename T>
constexpr Vector2<T>
Vector2<T>::operator+(const Vector2<T>& other) const
{
    return Vector2(X + other.X, Y + other.Y);
}

template <typename T>
constexpr Vector2<T>
Vector2<T>::operator-(const Vector2<T>& other) const
{
    return Vector2(X - other.X, Y - other.Y);
}

template <typename T>
constexpr Vector2<T>
Vector2<T>::operator*(T scale) const
{
    return Vector2(X * scale, Y * scale);
}

template <typename T>
constexpr Vector2<T>
Vector2<T>::operator/(T scale) const
{
    return Vector2(X / scale, Y / scale);
}


template <typename T>
constexpr bool
Vector2<T>::operator==(const Vector2<T>& other) const
{
    return X == other.X && Y == other.Y;
}

template <typename T>
constexpr bool
Vector2<T>::operator!=(const Vector2<T>& other) const
{
    return !operator==(other);
}


template <typename T>
constexpr T
Vector2<T>::lengthSq() const
{
    return X * X + Y * Y;
}

template <typename T>
constexpr T
Vector2<T>::length() const
{
    return Maths::sqrt(lengthSq());
}


template <typename T>
constexpr void
Vector2<T>::normalize()
{
    const T vectorLength = length();

    X /= vectorLength;
    Y /= vectorLength;
}
