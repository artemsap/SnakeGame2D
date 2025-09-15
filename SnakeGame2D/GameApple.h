#pragma once

#include <SFML/Graphics.hpp>
#include "IDraw.h"
#include "GameSnake.h"

class GameApple : public IDraw
{
public:
	GameApple(float radius, std::size_t pointCount);
	void Draw(sf::RenderWindow& window) override;
	void SetPosition(const sf::Vector2f& position);
private:
	sf::CircleShape shape;
	sf::Color color{ 0,0,0,255 };
};

