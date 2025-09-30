#include "GameApp.h"

#include <windows.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR    lpCmdLine,	_In_ int       nCmdShow)
{
	GameApp app({.width = 1000, .height = 1000, .title = "SFML works!" }, { .width = 10, .height = 10, .snakeSpeed = 4 });
	app.Run();
}