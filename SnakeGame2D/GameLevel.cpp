#include "GameLevel.h"

GameLevel::GameLevel(sf::Vector2u sizeLevel, sf::Vector2u windowSize) : levelSize(sizeLevel)
{
	generateLevel(windowSize);
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

void GameLevel::generateLevel(sf::Vector2u windowSize)
{
	float gridWidth = static_cast<float>(windowSize.x) / static_cast<float>(levelSize.x);
	float gridHeight = static_cast<float>(windowSize.y) / static_cast<float>(levelSize.y);

	grid.reserve(static_cast<size_t>(4 * gridHeight * gridWidth));

	for (size_t i = 0; i < levelSize.x; i++)
	{
		for (size_t j = 0; j < levelSize.y; j++)
		{
			grid.push_back({ { i * gridWidth, j * gridHeight }, gridColor });
			grid.push_back({ { i * gridWidth, (j + 1) * gridHeight }, gridColor });
			grid.push_back({ { i * gridWidth, j * gridHeight }, gridColor });
			grid.push_back({ { (i + 1) * gridWidth, j * gridHeight }, gridColor });
		}
	}
}
