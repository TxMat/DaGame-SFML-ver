#include "AppServer.h"
#include "Network/MainNetwork.h"

int main() {
    auto app = AppServer();
    app.Init();
    app.MainLoop();
    
}