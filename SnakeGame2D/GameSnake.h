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

		SnakeElementInfo(sf::CircleShape shape_, sf::Vector2i gridPosition_)
		{
			shape = shape_;
			gridPosition = gridPosition;
		}

		void SetGridPosition(sf::Vector2i newPos, const sf::Vector2f& tileSize)
		{
			gridPosition = newPos;
			shape.setPosition({ gridPosition.x * tileSize.x, gridPosition.y * tileSize.y });
		}
	};

public:
	GameSnake(float speed, GameApple& apple, const sf::Vector2f& tileSize, const sf::Vector2u& levelSize);
	void Draw(sf::RenderWindow& window) override;
	void MoveOneStep();
	void ChangeHeadDirection(Direction direction);
	const std::vector<SnakeElementInfo>& GetSnakeElelmenets() const;
	bool IsPlayerLose() const;

private:
	void addNewSnakeElement(sf::Vector2i gridPosition);
	bool checkAppleCollision();
	bool checkSelfCollision();
	bool checkWallCollision();

	const std::array<sf::Vector2i, 4> delta = { sf::Vector2i{0, -1}, sf::Vector2i{0, 1}, sf::Vector2i{1, 0}, sf::Vector2i{-1, 0} };

	const sf::Vector2f tileSize;
	const sf::Vector2u levelSize;
	GameApple& apple;

	sf::Clock clock;

	float speed = 2.0f; //tiles per sec
	const sf::Color baseColor = { 30, 89, 69, 255 };
	sf::CircleShape baseShape;
	Direction headDirection;
	std::vector<SnakeElementInfo> snakeElements;

	bool lose = false;
};

