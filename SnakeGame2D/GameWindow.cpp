#include "GameWindow.h"
#include <iostream>

GameWindow::GameWindow(const WindowSettings& windowSettings, const GameLevel::LevelSettings& levelSettings)
	: window(sf::VideoMode(sf::Vector2u{ windowSettings.width, windowSettings.height }), windowSettings.title)
	, level(levelSettings, window.getSize())
{
	bindKeys();
}

void GameWindow::Draw()
{
	const auto onCloseLambda = [&](const sf::Event::Closed&)
	{
		window.close();
	};

	while (window.isOpen())
	{
		window.handleEvents(onCloseLambda, keyboardBindings);

		window.clear(backgroundColor);
		level.Draw(window);
		window.display();

		if (level.IsPlayerLose())
		{
			window.close();
		}
	}
}

void GameWindow::bindKeys()
{
	GameSnake& snake = level.GetSnake();
	keyboardBindings.bind(sf::Keyboard::Scancode::W, [&snake]()	{ snake.ChangeHeadDirection(GameSnake::Direction::UP); });
	keyboardBindings.bind(sf::Keyboard::Scancode::S, [&snake]()	{ snake.ChangeHeadDirection(GameSnake::Direction::DOWN); });
	keyboardBindings.bind(sf::Keyboard::Scancode::A, [&snake]()	{ snake.ChangeHeadDirection(GameSnake::Direction::LEFT); });
	keyboardBindings.bind(sf::Keyboard::Scancode::D, [&snake]()	{ snake.ChangeHeadDirection(GameSnake::Direction::RIGHT); });
}
