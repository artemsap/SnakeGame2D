#pragma once

#include "IDraw.h"
#include "GameSnake.h"
#include "GameApple.h"
#include <vector>

class GameLevel : public IDraw
{
public:
	struct LevelSettings
	{
		uint32_t width = 10;
		uint32_t height = 10;
		float snakeSpeed = 5.0f;
	};

public:
	GameLevel(const LevelSettings& settings, const sf::Vector2u& windowSize);
	void Draw(sf::RenderWindow& window) override;
	GameSnake& GetSnake();
	bool IsPlayerLose() const;
private:
	void generateGrid();

	const sf::Color gridColor{ 127, 202, 0, 255 };

	sf::Vector2u levelSize;
	sf::Vector2f tileSize;
	std::vector<sf::Vertex> grid;

	GameApple apple;
	GameSnake snake;
};

