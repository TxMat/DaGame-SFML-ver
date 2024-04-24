#include "SFML/Graphics.hpp"

const unsigned int WIDTH = 1920u;
const unsigned int HEIGHT = 1080u;

#include "App.h"

int main()
{
    auto app = App();
    app.Init(WIDTH, HEIGHT);

}