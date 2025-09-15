#include "GameApple.h"

GameApple::GameApple(float radius, std::size_t pointCount) : shape(radius, pointCount)
{
	shape.setPosition({ -100,100 });
}

void GameApple::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

void GameApple::SetPosition(const sf::Vector2f& position)
{
	shape.setPosition(position);
}
