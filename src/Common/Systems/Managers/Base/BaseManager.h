    //
    // Created by uranus on 01/05/24.
    //

    #ifndef CMAKESFMLPROJECT_BASEMANAGER_H
    #define CMAKESFMLPROJECT_BASEMANAGER_H

    #include "SFML/System/Time.hpp"
    #include "SFML/Graphics/RenderWindow.hpp"

    // Forward declaration
    class SceneManager;

    class BaseManager {
    public:

        explicit BaseManager(SceneManager *Sm) : m_sm(Sm) {};

        virtual void FixedTick(float deltaTime) = 0;

        virtual void UnrestrictedTick(float deltaTime) = 0;

        virtual void Render(sf::RenderWindow &window) = 0;

    protected:
        SceneManager* m_sm;

    };


    #endif //CMAKESFMLPROJECT_BASEMANAGER_H
