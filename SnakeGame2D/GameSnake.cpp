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
	snakeElements.push_back({ baseShape, sf::Vector2i(0, 0), Direction::RIGHT });
}

void GameSnake::Draw(sf::RenderWindow& window)
{
	for (const auto& snakeElement : snakeElements)
	{
		window.draw(snakeElement.shape);
	}
}

void GameSnake::MoveOneStep()
{
	if (clock.getElapsedTime().asSeconds() > 1 / speed)
	{
		clock.restart();
		std::cout << "Move One Step \n";

		auto& front = snakeElements.front();
		auto gridPosition = front.gridPosition;
		auto prevGridPosition = gridPosition;
		auto prevDirection = front.direction;
		gridPosition += delta[static_cast<size_t>(front.direction)];
		front.gridPosition = gridPosition;
		front.shape.setPosition({ gridPosition.x * tileSize.x, gridPosition.y * tileSize.y });
		
		for (size_t i = 1; i < snakeElements.size(); i++)
		{
			auto prevprev = snakeElements[i].gridPosition;
			auto prevprevdir = snakeElements[i].direction;
			snakeElements[i].gridPosition = prevGridPosition;
			snakeElements[i].direction = prevDirection;
			snakeElements[i].shape.setPosition({ snakeElements[i].gridPosition.x * tileSize.x, snakeElements[i].gridPosition.y * tileSize.y });
			prevGridPosition = prevprev;
			prevDirection = prevprevdir;
		}

		if (checkApple())
		{
			addCircle();
			apple.GenerateNewPos(*this);
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
	snakeElements.front().direction = direction;

	if (direction == Direction::UP)
	{
		std::cout << "MOVE UP \n";
	}
	else if (direction == Direction::DOWN)
	{
		std::cout << "MOVE DOWN \n";
	}
	else if (direction == Direction::RIGHT)
	{
		std::cout << "MOVE RIGHT \n";
	}
	else if (direction == Direction::LEFT)
	{
		std::cout << "MOVE LEFT \n";
	}
}

const std::vector<GameSnake::SnakeElementInfo>& GameSnake::GetSnakeElelmenets() const
{
	return snakeElements;
}

bool GameSnake::IsPlayerLose() const
{
	return lose;
}

void GameSnake::addCircle()
{
	std::cout << "SNAKE IS GROWING\n";
	auto backElement = snakeElements.back();
	size_t index;
	if (backElement.direction == Direction::UP)
	{
		index = static_cast<size_t>(Direction::DOWN);
	}	
	else if (backElement.direction == Direction::DOWN)
	{
		index = static_cast<size_t>(Direction::UP);
	}
	else if (backElement.direction == Direction::LEFT)
	{
		index = static_cast<size_t>(Direction::RIGHT);
	}
	else if (backElement.direction == Direction::RIGHT)
	{
		index = static_cast<size_t>(Direction::LEFT);
	}

	auto gridPosition = backElement.gridPosition - delta[index];
	snakeElements.push_back({ baseShape, gridPosition, backElement.direction});
	snakeElements.back().shape.setPosition({ gridPosition.x * tileSize.x, gridPosition.y * tileSize.y });
}

bool GameSnake::checkApple()
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
