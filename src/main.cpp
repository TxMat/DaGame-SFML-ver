#include "AppServer.h"
#include "Network/MainNetwork.h"
#include "AppClient.h"
#include "Common/Globals.h"

int main() {
    if (IS_CLIENT) {
        auto app = AppClient();
        app.Init();
        app.MainLoop();
    } else {
        auto app = AppServer();
        app.Init();
        app.MainLoop();
    }
    
}