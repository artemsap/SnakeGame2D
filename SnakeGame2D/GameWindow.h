#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "KeyboardBinding.h"
#include "GameLevel.h"

class GameWindow
{
public:
	struct WindowSettings
	{
		uint32_t width = 1024;
		uint32_t height = 1024;
		std::string title = "Title";
	};

public:
	GameWindow(const WindowSettings& windowSettings, const GameLevel::LevelSettings& levelSettings);
	void Draw();

private:
	void bindKeys();

	const sf::Color backgroundColor{ 167, 252, 0, 255 };
	sf::RenderWindow window;

	KeyboardBinding keyboardBindings;
	GameLevel level;
};
