#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow{ { 1920u, 1080u }, "CMake SFML Project" };
    window.setFramerateLimit(144);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (/*m_scene->IsPlaying() */false)
        {
            if (/*UpdateTime() */ false)
            {
                //m_scene->Update();
                //m_scene->Render();
            }
        }
        else
        {
            //m_window->close();
        }

        window.clear();
        window.display();
    }

}