#include "GameLevel.h"

GameLevel::GameLevel(const LevelSettings& settings, const sf::Vector2u& windowSize) :
	gridSize(settings.height, settings.width),
	tileSize(static_cast<float>(windowSize.x) / gridSize.x, static_cast<float>(windowSize.y) / gridSize.y),
	apple(tileSize, gridSize),
	snake(settings.snakeSpeed, apple, tileSize)
{
	generateGrid();
	apple.GenerateNewPos(snake);
}

void GameLevel::Draw(sf::RenderWindow& window)
{
	window.draw(grid.data(), grid.size(), sf::PrimitiveType::Lines);
	snake.Draw(window);
	apple.Draw(window);
	snake.MoveOneStep();
}

GameSnake& GameLevel::GetSnake()
{
	return snake;
}

void GameLevel::generateGrid()
{
	grid.reserve(static_cast<size_t>(4 * tileSize.x * tileSize.y));

	for (size_t i = 0; i < gridSize.x; i++)
	{
		for (size_t j = 0; j < gridSize.y; j++)
		{
			grid.push_back({ { i * tileSize.x, j * tileSize.y }, gridColor });
			grid.push_back({ { i * tileSize.x, (j + 1) * tileSize.y }, gridColor });
			grid.push_back({ { i * tileSize.x, j * tileSize.y }, gridColor });
			grid.push_back({ { (i + 1) * tileSize.x, j * tileSize.y }, gridColor });
		}
	}
}
