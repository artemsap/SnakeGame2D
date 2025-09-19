#pragma once

#include "GameWindow.h"

#include <memory>

class GameApp
{
public:
	GameApp(const GameWindow::WindowSettings& windowSettings, const GameLevel::LevelSettings& levelSettings);
	void Run();
private:
	GameWindow window;
};
