#pragma once

#include "IDraw.h"
#include "GameApple.h"
#include "GameSnake.h"

class GameLevel : public IDraw
{
public:
	void Draw(sf::RenderWindow& window) override;
private:
	GameSnake snake;
	GameApple apple{ 100, 30 };
};

