#include "GameApp.h"

int main()
{
    GameApp app({ 1000, 1000, "SFML works!" }, {10, 10, 4});
    app.Run();
}