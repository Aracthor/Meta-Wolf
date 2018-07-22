#pragma once

#include "Color.hpp"
#include "ConstexprString.hpp"
#include "Keyboard.hpp"
#include "Map.hpp"
#include "Vector2.hpp"

template <unsigned int WindowWidth, unsigned int WindowHeight>
class	GameEngine
{
public:
    template <std::size_t GAME_STATE_LENGTH>
    constexpr		GameEngine(const char(&previousGameState)[GAME_STATE_LENGTH], Keyboard::Key pressedKey);

    constexpr auto	gameOutput() const;
    constexpr auto	stateOutput() const;
    constexpr int	returnValue() const;

private:
    template <std::size_t GAME_STATE_LENGTH>
    constexpr void	readGameState(const char(&previousGameState)[GAME_STATE_LENGTH]);
    constexpr void	processKeyboardInput(Keyboard::Key pressedKey);
    constexpr void	processColumn(const auto& map, unsigned int columnId);

private:
    Keyboard::Key	m_pressedKey;
    Vector2f		m_playerPosition;
    float		m_playerAngle;
    Vector2f		m_playerDirection;
    char	        m_output[WindowHeight * WindowWidth];
    Color::Type		m_colors[WindowHeight * WindowWidth];
};

#include "GameEngine.ipp"
