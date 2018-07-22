constexpr auto	GetColorAsConstexprString(Color color)
{
    const char colorChar = static_cast<char>(color) + '0';
    return CreateConstexprString("\x1B[3") + colorChar + 'm';
}
