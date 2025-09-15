#include "GameLevel.h"


GameLevel::GameLevel(sf::Vector2u size) : levelSize(size)
{}

void GameLevel::Draw(sf::RenderWindow& window)
{
	window.draw(grid.data(), grid.size(), sf::PrimitiveType::Lines);
	snake.Draw(window);
	apple.Draw(window);
}

GameSnake& GameLevel::GetSnake()
{
	return snake;
}
