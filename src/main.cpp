#include "SFML/Graphics.hpp"
#include "Game/MainScene.h"

#include "App.h"
#include "Common/Globals.h"
#include "Network/MainNetwork.h"

int main() {

    auto net = MainNetwork();
    net.start();

    auto app = App();
    app.Init();
    app.MainLoop();
    
}