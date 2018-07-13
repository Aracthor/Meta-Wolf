#include <iostream>

#include "Keyboard.hpp"

int	main()
{
    constexpr Keyboard::Key	key = Keyboard::GetKeyPressed();
    constexpr auto output = Keyboard::GetKeyAsConstexprString<key>();

    for (const char& c : output)
	std::cout << c;

    return key == Keyboard::Escape;
}
