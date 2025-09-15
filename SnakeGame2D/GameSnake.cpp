#include "GameSnake.h"
#include "GameApple.h"

#include <iostream>

GameSnake::GameSnake(GameApple& _apple, sf::Vector2f _gridSize) : apple(_apple), gridSize(_gridSize), baseShape(std::min(gridSize.x, gridSize.y) / 2)
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
	if (clock.getElapsedTime().asSeconds() > speed)
	{
		clock.restart();
		std::cout << "Move One Step \n";

		auto& front = snakeElements.front();
		auto gridPosition = front.gridPosition;
		auto prevGridPosition = gridPosition;
		auto prevDirection = front.direction;
		gridPosition += delta[static_cast<size_t>(front.direction)];
		front.gridPosition = gridPosition;
		front.shape.setPosition({ gridPosition.x * gridSize.x, gridPosition.y * gridSize.y });
		
		for (size_t i = 1; i < snakeElements.size(); i++)
		{
			auto prevprev = snakeElements[i].gridPosition;
			auto prevprevdir = snakeElements[i].direction;
			snakeElements[i].gridPosition = prevGridPosition;
			snakeElements[i].direction = prevDirection;
			snakeElements[i].shape.setPosition({ snakeElements[i].gridPosition.x * gridSize.x, snakeElements[i].gridPosition.y * gridSize.y });
			prevGridPosition = prevprev;
			prevDirection = prevprevdir;
		}

		if (checkApple())
		{
			addCircle();
			apple.GenerateNewPos(*this);
		}

		if (checkSelfCollision())
		{
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
	snakeElements.back().shape.setPosition({ gridPosition.x * gridSize.x, gridPosition.y * gridSize.y });
}

bool GameSnake::checkApple()
{
	return snakeElements.front().gridPosition == apple.GetPositionOnGrid();
}

bool GameSnake::checkSelfCollision()
{
	return false;
}