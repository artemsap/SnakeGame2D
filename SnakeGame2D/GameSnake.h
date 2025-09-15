#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "IDraw.h"

class GameSnake : public IDraw
{
public:
	GameSnake() = default;
	void Draw(sf::RenderWindow& window) override;
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
private:
	std::vector<sf::CircleShape> circles;
	sf::Color color;
};

