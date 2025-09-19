#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <array>

#include "IDraw.h"

class GameApple;

class GameSnake : public IDraw
{
public:
	enum class Direction : size_t
	{
		UP = 0,
		DOWN = 1,
		RIGHT = 2,
		LEFT = 3
	};

private:
	struct SnakeElementInfo
	{
		sf::CircleShape shape;
		sf::Vector2i gridPosition;
		Direction direction;
	};

public:
	GameSnake(float speed, GameApple& apple, sf::Vector2f gridSize);
	void Draw(sf::RenderWindow& window) override;
	void MoveOneStep();
	void ChangeDirection(Direction direction);
private:
	void addCircle();
	bool checkApple();
	bool checkSelfCollision();

	const std::array<sf::Vector2i, 4> delta = { sf::Vector2i{0, -1}, sf::Vector2i{0, 1}, sf::Vector2i{1, 0}, sf::Vector2i{-1, 0} };
	const sf::Vector2f gridSize;
	const float speed = 2.0f; //tiles per sec

	const sf::Color baseColor = { 30, 89, 69, 255 };
	sf::CircleShape baseShape;

	GameApple& apple;
	sf::Clock clock;

	std::vector<SnakeElementInfo> snakeElements;
};

