#include "SFML/Graphics.hpp"
#include "Game/MainScene.h"

#include "App.h"
#include "Common/Globals.h"

int main()
{
    auto app = App();
    app.Init(WIDTH, HEIGHT);
    app.MainLoop();
}