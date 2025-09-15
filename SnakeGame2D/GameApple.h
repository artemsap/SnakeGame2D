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
	sf::Vector2i GeneratePositionOnGrid(const GameSnake& snake);

	sf::Color color{ 0,0,0,255 };
	sf::Vector2i positionOnGrid;
	sf::Vector2f tileSize;
	sf::Vector2u gridSize;
	sf::CircleShape shape;
};

