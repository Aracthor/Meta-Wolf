#include <iostream>

constexpr const char previousGameState[] = ""
#include "game_state.txt"
    ;

#include "GameEngine.hpp"
#include "Keyboard.hpp"

int	main()
{
    constexpr Keyboard::Key	keyboardInput = Keyboard::GetKeyPressed();
    constexpr auto		gameState = GameEngine<WINDOW_WIDTH, WINDOW_HEIGHT>(previousGameState, keyboardInput);

    constexpr auto gameOutput = gameState.gameOutput();
    constexpr auto stateOutput = gameState.stateOutput();

    for (const char& c : gameOutput)
	std::cout << c;
    for (const char& c : stateOutput)
	std::cerr << c;

    return gameState.returnValue();
}
