#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <unordered_map>
#include <functional>

class KeyboardBinding
{
public:
	void operator()(const sf::Event::KeyPressed& keyPressedEvent);
	void bind(sf::Keyboard::Scancode code, const std::function<void()>& function);
private:
	std::unordered_map<sf::Keyboard::Scancode, std::function<void()>> bindings;
};

