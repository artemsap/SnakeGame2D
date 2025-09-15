#include "KeyboardBinding.h"

void KeyboardBinding::operator()(const sf::Event::KeyPressed& keyPressedEvent)
{
	auto find = bindings.find(keyPressedEvent.scancode);
	if (find != bindings.end())
	{
		find->second();
	}
}

void KeyboardBinding::bind(sf::Keyboard::Scancode code, const std::function<void()>&function)
{
	bindings[code] = function;
}
