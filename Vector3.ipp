#include "Maths.hpp"

template <typename T>
constexpr T
Vector3<T>::dot(const Vector3<T>& u, const Vector3<T>& v)
{
    return (u.x * v.x + u.y * v.y + u.z * v.z);
}

template <typename T>
constexpr T
Vector3<T>::cross(const Vector3<T>& u, const Vector3<T>& v)
{
    return Vector3<T>
    (
	u.y * v.z - u.z * v.y,
	u.z * v.x - u.x * v.z,
	u.x * v.y - u.y * v.x,
    );
}


template <typename T>
constexpr
Vector3<T>::Vector3() :
    X(0.f),
    Y(0.f),
    Z(0.f)
{
}

template <typename T>
constexpr
Vector3<T>::Vector3(T x, T y, T z) :
    X(x),
    Y(y),
    Z(z)
{
}

template <typename T>
constexpr
Vector3<T>::Vector3(const Vector3<T>& other) :
    X(other.X),
    Y(other.Y),
    Z(other.Z)
{
}


template <typename T>
constexpr void
Vector3<T>::operator+=(const Vector3<T>& other)
{
    X += other.X;
    Y += other.Y;
    Z += other.Z;
}

template <typename T>
constexpr void
Vector3<T>::operator-=(const Vector3<T>& other)
{
    X -= other.X;
    Y -= other.Y;
    Z -= other.Z;
}

template <typename T>
constexpr void
Vector3<T>::operator*=(T scale)
{
    X *= scale;
    Y *= scale;
    Z *= scale;
}

template <typename T>
constexpr void
Vector3<T>::operator/=(T scale)
{
    X /= scale;
    Y /= scale;
    Z /= scale;
}


template <typename T>
constexpr Vector3<T>
Vector3<T>::operator+(const Vector3<T>& other) const
{
    return Vector3(X + other.X, Y + other.Y, Z + other.Z);
}

template <typename T>
constexpr Vector3<T>
Vector3<T>::operator-(const Vector3<T>& other) const
{
    return Vector3(X - other.X, Y - other.Y, Z - other.Z);
}

template <typename T>
constexpr Vector3<T>
Vector3<T>::operator*(T scale) const
{
    return Vector3(X * scale, Y * scale, Z * scale);
}

template <typename T>
constexpr Vector3<T>
Vector3<T>::operator/(T scale) const
{
    return Vector3(X / scale, Y / scale, Z / scale);
}


template <typename T>
constexpr bool
Vector3<T>::operator==(const Vector3<T>& other) const
{
    return X == other.X && Y == other.Y && Z == other.Z;
}

template <typename T>
constexpr bool
Vector3<T>::operator!=(const Vector3<T>& other) const
{
    return !operator==(other);
}


template <typename T>
constexpr T
Vector3<T>::lengthSq() const
{
    return X * X + Y * Y + Z * Z;
}

template <typename T>
constexpr T
Vector3<T>::length() const
{
    return Maths::sqrt(lengthSq());
}


template <typename T>
constexpr void
Vector3<T>::normalize()
{
    const T vectorLength = length();

    X /= vectorLength;
    Y /= vectorLength;
    Z /= vectorLength;
}
