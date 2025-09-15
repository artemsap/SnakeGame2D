#include "GameWindow.h"
#include <iostream>

GameWindow::GameWindow(const sf::VideoMode& mode, std::string header) : window(mode, header), level(sf::Vector2f(10, 10), sf::Vector2f(mode.size))
{
	GameSnake& snake = level.GetSnake();
	keyboardBindings.bind(sf::Keyboard::Scancode::W, [&snake](){snake.moveUp();});
	keyboardBindings.bind(sf::Keyboard::Scancode::S, [&snake](){snake.moveDown();});
	keyboardBindings.bind(sf::Keyboard::Scancode::A, [&snake](){snake.moveLeft();});
	keyboardBindings.bind(sf::Keyboard::Scancode::D, [&snake](){snake.moveRight();});
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
	}
}
