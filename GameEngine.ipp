namespace
{
constexpr float
calcDistance(auto& map, const Vector2f& playerPosition, const Vector2f& vector, float vectorNorm, char& outWall)
{
    Vector2f	movement = vector;
    Vector2f	position = playerPosition + movement;

    while (!map.pointIsInsideWall(position))
    {
    	position += movement;
    }
    movement *= -0.1f;
    while (map.pointIsInsideWall(position))
    {
    	position += movement;
    }
    movement *= -0.1f;
    while (!map.pointIsInsideWall(position))
    {
    	position += movement;
    }
    const float		distance = (playerPosition - position).length() / vectorNorm * 10.f;
    unsigned int	xAsInt = static_cast<unsigned int>(position.X);

    if (xAsInt % 1000 == 0 || xAsInt % 1000 == 999)
	outWall = '#';
    else
	outWall = '@';

    return distance;
}
}


template <unsigned int WindowWidth, unsigned int WindowHeight>
template <std::size_t GAME_STATE_LENGTH>
constexpr
GameEngine<WindowWidth, WindowHeight>::GameEngine(const char(&previousGameState)[GAME_STATE_LENGTH], Keyboard::Key pressedKey) :
    m_pressedKey(pressedKey),
    m_playerPosition(),
    m_playerAngle(0.f),
    m_playerDirection(),
    m_output()
{
    readGameState(previousGameState);
    processKeyboardInput(pressedKey);
    constexpr const char mapString[] = ""
#include "map.txt"
	;
    auto map = Map(mapString);

    for (unsigned int i = 0; i < WindowWidth * WindowHeight; i++)
    {
	m_output[i] = ' ';
    }
    for (unsigned int i = 0; i < WindowWidth; ++i)
    {
	processColumn(map, i);
    }
}

template <unsigned int WindowWidth, unsigned int WindowHeight>
constexpr auto
GameEngine<WindowWidth, WindowHeight>::gameOutput() const
{
    return CreateConstexprString(m_output);
}

template <unsigned int WindowWidth, unsigned int WindowHeight>
constexpr auto
GameEngine<WindowWidth, WindowHeight>::stateOutput() const
{
    auto positionX = CreateConstexprStringFromInt(static_cast<unsigned int>(m_playerPosition.X));
    auto positionY = CreateConstexprStringFromInt(static_cast<unsigned int>(m_playerPosition.Y));
    auto angle = CreateConstexprStringFromInt(static_cast<unsigned int>(m_playerAngle));
    return positionX + ',' + positionY + '\n' + angle + '\n';
}

template <unsigned int WindowWidth, unsigned int WindowHeight>
constexpr int
GameEngine<WindowWidth, WindowHeight>::returnValue() const
{
    return (Keyboard::GetKeyPressed() == Keyboard::Escape);
}



template <unsigned int WindowWidth, unsigned int WindowHeight>
template <std::size_t GAME_STATE_LENGTH>
constexpr void
GameEngine<WindowWidth, WindowHeight>::readGameState(const char(&previousGameState)[GAME_STATE_LENGTH])
{
    const ConstexprString gameStateString(previousGameState);
    const std::size_t positionStartIndex = gameStateString.indexOf('\n') + 1;
    const std::size_t commaIndex = gameStateString.indexOf(',', positionStartIndex);
    const std::size_t positionEndIndex = gameStateString.indexOf('\n', positionStartIndex);
    const std::size_t angleStartIndex = positionEndIndex + 1;
    const std::size_t angleEndIndex = gameStateString.indexOf('\n', angleStartIndex);

    const auto playerPosX = gameStateString.substr(positionStartIndex, commaIndex - positionStartIndex);
    const auto playerPosY = gameStateString.substr(commaIndex + 1, positionEndIndex - commaIndex - 1);
    const auto playerAngle = gameStateString.substr(angleStartIndex, angleEndIndex - angleStartIndex);

    m_playerPosition.X = static_cast<float>(playerPosX.asNumber());
    m_playerPosition.Y = static_cast<float>(playerPosY.asNumber());
    m_playerAngle = static_cast<float>(playerAngle.asNumber());
    const float angleInRadians = Maths::degToRad(m_playerAngle);
    m_playerDirection.X = Maths::cos(angleInRadians);
    m_playerDirection.Y = Maths::sin(angleInRadians);
}

template <unsigned int WindowWidth, unsigned int WindowHeight>
constexpr void
GameEngine<WindowWidth, WindowHeight>::processKeyboardInput(Keyboard::Key pressedKey)
{
    constexpr float speed = 150.f;
    constexpr float turningSpeed = 15.f;

    switch (pressedKey)
    {
    case Keyboard::Front:
	m_playerPosition += m_playerDirection * speed;
	break;
    case Keyboard::Back:
	m_playerPosition -= m_playerDirection * speed;
	break;
    case Keyboard::Right:
	m_playerAngle += turningSpeed;
	break;
    case Keyboard::Left:
	m_playerAngle -= turningSpeed;
	break;
    case Keyboard::Escape:
    default:
	break;
    }

    if (m_playerAngle >= 360.f)
	m_playerAngle -= 360.f;
    if (m_playerAngle < 0.f)
	m_playerAngle += 360.f;
}


template <unsigned int WindowWidth, unsigned int WindowHeight>
constexpr void
GameEngine<WindowWidth, WindowHeight>::processColumn(const auto& map, unsigned int columnId)
{
    Vector2f	vector;
    char	wallChar = '#';

    vector.X = 10.f;
    vector.Y = static_cast<float>(10.f * (static_cast<float>(WindowWidth) - 2.f * columnId)) / static_cast<float>(WindowWidth);
    const float	angle = Maths::degToRad(m_playerAngle);
    const float angleCos = Maths::cos(angle);
    const float angleSin = Maths::sin(angle);
    Vector2f	rotatedVector;
    rotatedVector.X = (vector.X * angleCos + vector.Y * angleSin);
    rotatedVector.Y = (vector.X * angleSin - vector.Y * angleCos);

    const float distance = calcDistance(map, m_playerPosition, rotatedVector, rotatedVector.length(), wallChar);
    const unsigned int wallSize = static_cast<float>(WindowHeight) * 500.f / distance;
    const unsigned int startWallOffset = (wallSize >= WindowHeight) ? 0 : WindowHeight / 2 - wallSize / 2;
    const unsigned int endWallOffset = (wallSize >= WindowHeight) ? WindowHeight - 1 : WindowHeight / 2 + wallSize / 2;
    for (unsigned int y = startWallOffset; y < endWallOffset; y++)
    {
    	m_output[y * WindowWidth + columnId] = wallChar;
    }
}
