//
// Created by uranus on 4/24/24.
//

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "Common/Object.h"

#ifndef CMAKESFMLPROJECT_APP_H
#define CMAKESFMLPROJECT_APP_H


class App {

public:
    App();

    void Update();

    void Init(unsigned int width, unsigned int height);

    void MainLoop();

    void Render();

private:

    std::vector<Object> m_objectList;

    sf::Text m_fps;
    sf::Text m_debug_text;
    sf::Font m_font;

    sf::RenderWindow* m_window;

    sf::Clock m_clock;
    sf::Time m_currentTime;
    sf::Time m_lastTime;

};


#endif //CMAKESFMLPROJECT_APP_H
