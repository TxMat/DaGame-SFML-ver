#include "SFML/Graphics.hpp"

const unsigned int WIDTH = 1920u;
const unsigned int HEIGHT = 1080u;

int main()
{
    auto window = sf::RenderWindow{ { WIDTH, HEIGHT }, "Best App Ever" };
    window.setFramerateLimit(144);
    sf::RectangleShape shape = sf::RectangleShape(sf::Vector2f(100.0f, 200.0f));
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(50, 100);
    shape.setPosition(WIDTH/2, HEIGHT/2);

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
//        shape.move(5.f, 5.f);
        shape.rotate(5.0f);
        window.draw(shape);
        window.display();
    }

}