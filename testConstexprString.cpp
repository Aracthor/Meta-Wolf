#include <iostream>

#include "ConstexprString.hpp"

int	main()
{
    auto hello = ConstexprString("hello");
    auto world = ConstexprString("world");
    auto space = CreateConstexprStringFromChar(' ');

    hello[0] = 'H';
    auto result = hello + ' ' + world;
    auto resultCopy = ConstexprString(result);

    std::cout << hello << space << world << std::endl;
    std::cout << result << std::endl;
    std::cout << resultCopy << std::endl;

    return 0;
}
