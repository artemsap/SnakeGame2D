#pragma once

#include <SFML/Graphics.hpp>
#include "IDraw.h"

class GameApple : public IDraw
{
public:
	GameApple(float radius, std::size_t pointCount);
	void Draw(sf::RenderWindow& window) override;
private:
	sf::CircleShape apple;
};

