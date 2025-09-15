#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class KeyboardBinding
{
public:
	void operator()(const sf::Event::KeyPressed& keyPressedEvent);
};

