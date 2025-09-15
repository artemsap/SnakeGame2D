#include "GameLevel.h"


void GameLevel::Draw(sf::RenderWindow& window)
{
	//window.draw(/*spritelevel*/);
	snake.Draw(window);
	apple.Draw(window);
}

GameSnake& GameLevel::GetSnake()
{
	return snake;
}
