#include "GameApple.h"
#include "GameSnake.h"

GameApple::GameApple(sf::Vector2f tileSize_, sf::Vector2u gridSize_) :
	tileSize(tileSize_), shape(std::min(tileSize.x, tileSize.y) / 3), gridSize(gridSize_)
{
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
	//generation here
	return { 1, 1 };
}
