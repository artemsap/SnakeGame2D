#pragma once

#include "IDraw.h"
#include "GameApple.h"
#include "GameSnake.h"
#include <vector>

class GameLevel : public IDraw
{
public:
	GameLevel(sf::Vector2f size, sf::Vector2f windowSize);
	void Draw(sf::RenderWindow& window) override;
	GameSnake& GetSnake();
private:
	void generateLevel();

	sf::Vector2u gridSize;
	std::vector<sf::Vertex> grid;
	sf::Color gridColor{ 127, 202, 0, 255 };
	float tileWidth;
	float tileHeight;

	GameSnake snake;
	GameApple apple;
};

