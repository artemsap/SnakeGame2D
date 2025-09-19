#include "GameLevel.h"

GameLevel::GameLevel(const LevelSettings& settings, const sf::Vector2u& windowSize) :
	levelSize(settings.height, settings.width),
	tileSize(static_cast<float>(windowSize.x) / levelSize.x, static_cast<float>(windowSize.y) / levelSize.y),
	apple(tileSize, levelSize),
	snake(settings.snakeSpeed, apple, tileSize, levelSize),
	font("arial.ttf"),
	pointsText(font),
	speedText(font)
{
	generateGrid();
	apple.GenerateNewPos(snake);
	pointsText.setString("SCORE: " + std::to_string(points));
	pointsText.setCharacterSize(24);
	pointsText.setFillColor(sf::Color::Black);

	speedText.setString("SPEED: " + std::to_string(snake.GetSpeed()));
	speedText.setCharacterSize(24);
	speedText.setFillColor(sf::Color::Black);
	speedText.setPosition(sf::Vector2f(0, 40));
}

void GameLevel::Draw(sf::RenderWindow& window)
{
	window.draw(grid.data(), grid.size(), sf::PrimitiveType::Lines);
	snake.Draw(window);
	apple.Draw(window);
	auto result = snake.MoveOneStep();
	if (result == GameSnake::StepResult::EAT_APPLE)
	{
		points++;
		pointsText.setString("SCORE: " + std::to_string(points));
		speedText.setString("SPEED: " + std::to_string(snake.GetSpeed()));
	}
	else if (result == GameSnake::StepResult::DEAD)
	{
		lose = true;
	}
	window.draw(pointsText);
	window.draw(speedText);
}

GameSnake& GameLevel::GetSnake()
{
	return snake;
}

bool GameLevel::IsPlayerLose() const
{
	return lose;
}

int GameLevel::GetPoints() const
{
	return points;
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
