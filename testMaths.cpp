#include <iostream>

#include "Maths.hpp"

int	main()
{
    constexpr float	angles[] =
    {
	0.f,
	Maths::_PI / 4.f,
	Maths::_PI / 3.f,
	Maths::_PI / 2.f,
	Maths::_PI,
	Maths::_PI * 2.f
    };

    for (const float angle : angles)
    {
	std::cout << "cos(" << angle << ") = " << Maths::cos(angle) << std::endl;
    }
    std::cout << std::endl;

    for (const float angle : angles)
    {
	std::cout << "sin(" << angle << ") = " << Maths::sin(angle) << std::endl;
    }
    std::cout << std::endl;

    for (float n = 0; n < 10; n++)
    {
	std::cout << "Sqrt(" << n << ") = " << Maths::sqrt(n) << std::endl;
    }

    return 0;
}
