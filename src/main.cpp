#include "SFML/Graphics.hpp"
#include "Game/MainScene.h"

const unsigned int WIDTH = 1920u;
const unsigned int HEIGHT = 1080u;

int main()
{
    auto window = sf::RenderWindow{ { WIDTH, HEIGHT }, "Best App Ever" };
    window.setFramerateLimit(144);
    auto scene = MainScene();

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();

        window.draw(scene.GetSceneElements());
        window.display();
    }

}