#pragma once

#include "GameWindow.h"

#include <memory>

class GameApp
{
public:
	GameApp(uint32_t width, uint32_t height, const std::string& window_header);
	void Run();
private:
	GameWindow window;
};
