#include "GameLevel.h"

GameLevel::GameLevel(sf::Vector2f sizeLevel, sf::Vector2f windowSize) 
	: gridSize(sizeLevel), tileWidth(windowSize.x / gridSize.x), tileHeight(windowSize.y / gridSize.y), apple(std::min(tileWidth, tileHeight) / 3, 32)
{
	generateLevel();
}

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

void GameLevel::generateLevel()
{
	grid.reserve(static_cast<size_t>(4 * tileHeight * tileWidth));

	for (size_t i = 0; i < gridSize.x; i++)
	{
		for (size_t j = 0; j < gridSize.y; j++)
		{
			grid.push_back({ { i * tileWidth, j * tileHeight }, gridColor });
			grid.push_back({ { i * tileWidth, (j + 1) * tileHeight }, gridColor });
			grid.push_back({ { i * tileWidth, j * tileHeight }, gridColor });
			grid.push_back({ { (i + 1) * tileWidth, j * tileHeight }, gridColor });
		}
	}
}
