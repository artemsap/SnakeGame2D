#include "GameApp.h"

#include <windows.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR    lpCmdLine,	_In_ int       nCmdShow)
{
	GameApp app({ 1000, 1000, "SFML works!" }, GameLevel::LevelSettings{ .width = 10, .height = 10, .snakeSpeed = 4 });
	app.Run();
}