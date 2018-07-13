constexpr static const char frontKeys[] = "wW";
constexpr static const char backKeys[] = "sS";
constexpr static const char rightKeys[] = "dD";
constexpr static const char leftKeys[] = "aA";
constexpr static const char escapeKeys[] = "qQ";

template <typename T>
constexpr bool keyIsInList(char key, const T& keys)
{
    constexpr std::size_t keysNumber = sizeof(T) - 1;

    for (std::size_t i = 0; i < keysNumber; i++)
    {
	if (keys[i] == key)
	    return true;
    }
    return false;
}

constexpr Key
GetKeyPressed()
{
    constexpr char key = KEYBOARD_INPUT[0];

    if constexpr (keyIsInList(key, frontKeys))
    	return Keyboard::Front;
    else if constexpr (keyIsInList(key, backKeys))
    	return Keyboard::Back;
    else if constexpr (keyIsInList(key, rightKeys))
    	return Keyboard::Right;
    else if constexpr (keyIsInList(key, leftKeys))
    	return Keyboard::Left;
    else if constexpr (keyIsInList(key, escapeKeys))
    	return Keyboard::Escape;
    else
    	return Keyboard::Invalid;
}

template <Keyboard::Key key>
constexpr auto
GetKeyAsConstexprString()
{
    if constexpr (key == Keyboard::Front)
	return CreateConstexprString("Front");
    else if constexpr (key == Keyboard::Back)
	return CreateConstexprString("Back");
    else if constexpr (key == Keyboard::Right)
	return CreateConstexprString("Right");
    else if constexpr (key == Keyboard::Left)
	return CreateConstexprString("Left");
    else if constexpr (key == Keyboard::Escape)
	return CreateConstexprString("Escape");
    else
	return CreateConstexprString("Invalid");
}
