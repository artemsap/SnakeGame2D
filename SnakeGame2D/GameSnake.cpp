#include "GameSnake.h"
#include "GameApple.h"

#include <iostream>

GameSnake::GameSnake(float _speed, GameApple& _apple, const sf::Vector2f& _tileSize, const sf::Vector2u& _levelSize)
	: speed(_speed)
	, apple(_apple)
	, tileSize(_tileSize)
	, baseShape(std::min(tileSize.x, tileSize.y) / 2)
	, levelSize(_levelSize)
{
	snakeElements.push_back({ baseShape, sf::Vector2i{ 0,0 }, Direction::RIGHT });
}

void GameSnake::Draw(sf::RenderWindow& window)
{
	for (const auto& snakeElement : snakeElements)
	{
		window.draw(snakeElement.shape);
	}
}

void printDirection(GameSnake::Direction dir)
{
	switch (dir)
	{
	case GameSnake::Direction::UP:
		std::cout << "DIRECTION UP\n";
		break;
	case GameSnake::Direction::DOWN:
		std::cout << "DIRECTION DOWN\n";
		break;
	case GameSnake::Direction::LEFT:
		std::cout << "DIRECTION LEFT\n";
		break;
	case GameSnake::Direction::RIGHT:
		std::cout << "DIRECTION RIGHT\n";
		break;
	}
}

void GameSnake::MoveOneStep()
{
	if (clock.getElapsedTime().asSeconds() > 1 / speed)
	{
		clock.restart();
		std::cout << "Move One Step \n";

		auto& front = snakeElements.front();
		auto prevGridPosition = front.gridPosition;
		front.SetGridPosition(front.gridPosition + delta[static_cast<size_t>(front.direction)], tileSize);
		
		auto prevDirection = front.direction;

		std::cout << std::endl;
		printDirection(front.direction);

		for (size_t i = 1; i < snakeElements.size(); i++)
		{
			auto currentPosition = snakeElements[i].gridPosition;
			auto currentDirection = snakeElements[i].direction;
			snakeElements[i].SetGridPosition(prevGridPosition, tileSize);
			snakeElements[i].direction = prevDirection;
			prevGridPosition = currentPosition;
			prevDirection = currentDirection;
			printDirection(snakeElements[i].direction);
		}

		if (checkAppleCollision())
		{
			addNewSnakeElement();
			apple.GenerateNewPos(*this);
			speed += 0.1f;
		}

		if (checkSelfCollision() || checkWallCollision())
		{
			lose = true;
			std::cout << "YOU LOOSE\n";
		}
	}
}

void GameSnake::ChangeDirection(Direction direction)
{
	auto& frontElement = snakeElements.front();
	if (frontElement.direction == Direction::UP && direction == Direction::DOWN ||
		frontElement.direction == Direction::DOWN && direction == Direction::UP ||
		frontElement.direction == Direction::RIGHT && direction == Direction::LEFT ||
		frontElement.direction == Direction::LEFT && direction == Direction::RIGHT)
	{
		return;
	}

	frontElement.direction = direction;
}

const std::vector<GameSnake::SnakeElementInfo>& GameSnake::GetSnakeElelmenets() const
{
	return snakeElements;
}

bool GameSnake::IsPlayerLose() const
{
	return lose;
}

void GameSnake::addNewSnakeElement()
{
	std::cout << "SNAKE IS GROWING\n";
	auto backElement = snakeElements.back();
	auto gridPosition = backElement.gridPosition - delta[static_cast<size_t>(backElement.direction)];
	auto snakeElement = SnakeElementInfo{ baseShape, gridPosition, backElement.direction };
	snakeElement.shape.setPosition({ gridPosition.x * tileSize.x, gridPosition.y * tileSize.y });
	snakeElements.push_back(snakeElement);
}

bool GameSnake::checkAppleCollision()
{
	return snakeElements.front().gridPosition == apple.GetPositionOnGrid();
}

bool GameSnake::checkSelfCollision()
{
	sf::Vector2i headPosition = snakeElements.front().gridPosition;

	for (size_t i = 1; i < snakeElements.size(); i++)
	{
		if (headPosition == snakeElements[i].gridPosition)
		{
			return true;
		}
	}

	return false;
}

bool GameSnake::checkWallCollision()
{
	sf::Vector2i headPosition = snakeElements.front().gridPosition;
	if (headPosition.x < 0 || headPosition.y < 0 || headPosition.x == levelSize.x || headPosition.y == levelSize.y)
	{
		return true;
	}

	return false;
}
