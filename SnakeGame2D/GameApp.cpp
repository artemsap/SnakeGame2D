#include "GameApp.h"

GameApp::GameApp(const GameWindow::WindowSettings& windowSettings, const GameLevel::LevelSettings& levelSettings) 
	: window(windowSettings, levelSettings)
{}

void GameApp::Run()
{
	window.Draw();
}
