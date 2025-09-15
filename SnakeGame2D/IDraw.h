#pragma once
#include <SFML/Graphics.hpp>

class IDraw
{
public:
	virtual void Draw(sf::RenderWindow& window) = 0;
};