#pragma once

#include "IDraw.h"
#include "GameApple.h"
#include "GameSnake.h"
#include <vector>

class GameLevel : public IDraw
{
public:
	GameLevel(sf::Vector2u size, sf::Vector2u windowSize);
	void Draw(sf::RenderWindow& window) override;
	GameSnake& GetSnake();
private:
	void generateLevel(sf::Vector2u windowSize);

	GameSnake snake;
	GameApple apple{ 100, 30 };
	sf::Vector2u levelSize;
	std::vector<sf::Vertex> grid;
	sf::Color gridColor{ 127,202,0,255 };
};

