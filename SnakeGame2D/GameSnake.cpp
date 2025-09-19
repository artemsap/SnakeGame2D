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
	baseShape.setFillColor(baseColor);
	headDirection = Direction::RIGHT;
	snakeElements.push_back({ baseShape, sf::Vector2i{ 0,0 }});
}

void GameSnake::Draw(sf::RenderWindow& window)
{
	for (const auto& snakeElement : snakeElements)
	{
		window.draw(snakeElement.shape);
	}
}

GameSnake::StepResult GameSnake::MoveOneStep()
{
	if (clock.getElapsedTime().asSeconds() > 1 / speed)
	{
		clock.restart();

		auto& front = snakeElements.front();
		auto prevGridPosition = front.gridPosition;
		front.SetGridPosition(front.gridPosition + delta[static_cast<size_t>(headDirection)], tileSize);
		
		for (size_t i = 1; i < snakeElements.size(); i++)
		{
			auto currentPosition = snakeElements[i].gridPosition;
			snakeElements[i].SetGridPosition(prevGridPosition, tileSize);
			prevGridPosition = currentPosition;
		}

		if (checkAppleCollision())
		{
			addNewSnakeElement(prevGridPosition);
			apple.GenerateNewPos(*this);
			speed += 0.1f;
			return StepResult::EAT_APPLE;
		}

		if (checkSelfCollision() || checkWallCollision())
		{
			return StepResult::DEAD;
		}
	}

	return StepResult::NONE;
}

void GameSnake::ChangeHeadDirection(Direction direction)
{
	if (headDirection == Direction::UP && direction == Direction::DOWN ||
		headDirection == Direction::DOWN && direction == Direction::UP ||
		headDirection == Direction::RIGHT && direction == Direction::LEFT ||
		headDirection == Direction::LEFT && direction == Direction::RIGHT)
	{
		return;
	}

	headDirection = direction;
}

const std::vector<GameSnake::SnakeElementInfo>& GameSnake::GetSnakeElelmenets() const
{
	return snakeElements;
}

float GameSnake::GetSpeed() const
{
	return speed;
}

void GameSnake::addNewSnakeElement(sf::Vector2i gridPosition)
{
	auto snakeElement = SnakeElementInfo{ baseShape, gridPosition };
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
