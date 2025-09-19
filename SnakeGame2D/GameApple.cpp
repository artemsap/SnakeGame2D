#include "GameApple.h"
#include "GameSnake.h"

#include <cstdlib>

GameApple::GameApple(sf::Vector2f tileSize_, sf::Vector2u gridSize_) 
	: tileSize(tileSize_), shape(std::min(tileSize.x, tileSize.y) * sizeRatio), gridSize(gridSize_)
{
	srand(static_cast<unsigned>(time(0)));

	shape.setOrigin(-tileSize * sizeRatio * 0.5f);
	shape.setPosition(-tileSize);
	shape.setFillColor(color);
}

void GameApple::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

void GameApple::GenerateNewPos(const GameSnake& snake)
{
	positionOnGrid = generateRandomPositionOnGrid(snake);
	
	shape.setPosition({ positionOnGrid.x * tileSize.x, positionOnGrid.y * tileSize.y });
}

const sf::Vector2i& GameApple::GetPositionOnGrid() const
{
	return positionOnGrid;
}

sf::Vector2i GameApple::generateRandomPositionOnGrid(const GameSnake& snake)
{
	sf::Vector2i applePosition;
	
	bool isGenerated = false;
	while (!isGenerated)
	{
		applePosition.x = rand() % gridSize.x;
		applePosition.y = rand() % gridSize.y;

		for (const auto& element : snake.GetSnakeElelmenets())
		{
			if (applePosition == element.gridPosition)
			{
				break;
			}
		}

		isGenerated = true;
	}

	return applePosition;
}
