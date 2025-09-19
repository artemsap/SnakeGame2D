#pragma once

#include <SFML/Graphics.hpp>
#include "IDraw.h"
#include "GameSnake.h"

class GameSnake;

class GameApple : public IDraw
{
public:
	GameApple(sf::Vector2f tileSize, sf::Vector2u gridSize);
	void Draw(sf::RenderWindow& window) override;
	void GenerateNewPos(const GameSnake& snake);
	const sf::Vector2i& GetPositionOnGrid() const;
private:
	sf::Vector2i generateRandomPositionOnGrid(const GameSnake& snake);

	const sf::Color color{ 255, 20, 0, 255 };
	const float sizeRatio = 0.33f;

	sf::Vector2i positionOnGrid;
	sf::Vector2f tileSize;
	sf::Vector2u gridSize;
	sf::CircleShape shape;
};
