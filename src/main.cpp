#include "AppServer.h"
#include "Network/MainNetwork.h"
#include "AppClient.h"

int main() {
    auto app = AppClient();
    app.Init();
    app.MainLoop();
    
}