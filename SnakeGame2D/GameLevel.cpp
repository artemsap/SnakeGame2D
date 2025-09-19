#include "GameLevel.h"

GameLevel::GameLevel(const LevelSettings& settings, const sf::Vector2u& windowSize) :
	levelSize(settings.height, settings.width),
	tileSize(static_cast<float>(windowSize.x) / levelSize.x, static_cast<float>(windowSize.y) / levelSize.y),
	apple(tileSize, levelSize),
	snake(settings.snakeSpeed, apple, tileSize, levelSize)
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

bool GameLevel::IsPlayerLose() const
{
	return snake.IsPlayerLose();
}

void GameLevel::generateGrid()
{
	grid.reserve(static_cast<size_t>(4 * tileSize.x * tileSize.y));

	for (size_t i = 0; i < levelSize.x; i++)
	{
		for (size_t j = 0; j < levelSize.y; j++)
		{
			grid.push_back({ { i * tileSize.x, j * tileSize.y }, gridColor });
			grid.push_back({ { i * tileSize.x, (j + 1) * tileSize.y }, gridColor });
			grid.push_back({ { i * tileSize.x, j * tileSize.y }, gridColor });
			grid.push_back({ { (i + 1) * tileSize.x, j * tileSize.y }, gridColor });
		}
	}
}
