#include "GameApple.h"
#include "GameSnake.h"

#include <cstdlib>

GameApple::GameApple(sf::Vector2f tileSize_, sf::Vector2u gridSize_) :
	tileSize(tileSize_), shape(std::min(tileSize.x, tileSize.y) / 3), gridSize(gridSize_)
{
	srand(static_cast<unsigned>(time(0)));
	shape.setPosition(-tileSize);
}

void GameApple::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

void GameApple::GenerateNewPos(const GameSnake& snake)
{
	positionOnGrid = GeneratePositionOnGrid(snake);
	shape.setPosition({ positionOnGrid.x * tileSize.x, positionOnGrid.y * tileSize.y });
}

const sf::Vector2i& GameApple::GetPositionOnGrid() const
{
	return positionOnGrid;
}

sf::Vector2i GameApple::GeneratePositionOnGrid(const GameSnake& snake)
{
	int randPosX = rand() % gridSize.x;
	int randPosY = rand() % gridSize.y;
	return { randPosX , randPosY };
}
