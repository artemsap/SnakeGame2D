#include "GameWindow.h"
#include <iostream>

GameWindow::GameWindow(const sf::VideoMode& mode, std::string header) : window(mode, header)
{
	GameSnake& snake = level.GetSnake();
	keyboardBindings.bind(sf::Keyboard::Scancode::W, [&snake](){snake.moveUp();});
	keyboardBindings.bind(sf::Keyboard::Scancode::S, [&snake](){snake.moveDown();});
	keyboardBindings.bind(sf::Keyboard::Scancode::A, [&snake](){snake.moveLeft();});
	keyboardBindings.bind(sf::Keyboard::Scancode::D, [&snake](){snake.moveRight();});
}

void GameWindow::Run()
{
	sf::SoundBuffer soundBuffer("sound.mp3");
	sf::Sound sound(soundBuffer);

	sf::Texture sphere("sphere.png");
	sphere.setSmooth(true);

	const sf::Vector2f imageSize = sf::Vector2f(sphere.getSize());
	const sf::Vector2f winSize = sf::Vector2f(window.getSize());
	const sf::Vector2f sprintScale = { winSize.x / imageSize.x, winSize.y / imageSize.y };

	sf::Sprite sprite(sphere);
	sprite.setScale(sprintScale);

	const auto onCloseLambda = [&](const sf::Event::Closed&)
	{
		window.close();
	};

	while (window.isOpen())
	{
		window.handleEvents(onCloseLambda, keyboardBindings);

		window.clear();
		window.draw(sprite);
		window.display();
	}
}
