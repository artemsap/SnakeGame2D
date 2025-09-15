#pragma once

#include "IDraw.h"
#include "GameApple.h"
#include "GameSnake.h"
#include <vector>

class GameLevel : public IDraw
{
public:
	GameLevel(sf::Vector2u size);
	void Draw(sf::RenderWindow& window) override;
	GameSnake& GetSnake();
private:
	void generateLevel();

	GameSnake snake;
	GameApple apple{ 100, 30 };
	sf::Vector2u levelSize;
	std::vector<sf::Vertex> grid;
};

