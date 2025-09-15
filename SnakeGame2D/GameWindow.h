#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "KeyboardBinding.h"
#include "GameLevel.h"

class GameWindow 
{
public:
	GameWindow(const sf::VideoMode& mode, std::string header);

	void Draw();

private:
	sf::RenderWindow window;
	KeyboardBinding keyboardBindings;
	GameLevel level;
	sf::Color backgroundColor{ 167, 252, 0, 255 };
};

