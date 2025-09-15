#include "GameApp.h"

GameApp::GameApp(uint32_t width, uint32_t height, const std::string& window_header) 
{
	window = std::make_shared<GameWindow>(sf::VideoMode({ width, height }), window_header);
}

void GameApp::Run()
{
	window->Run();
}
