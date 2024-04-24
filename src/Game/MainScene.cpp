#include "MainScene.h"

MainScene::MainScene()
{
}

MainScene::~MainScene()
{
}

void MainScene::CreateScene()
{
    sf::RectangleShape shape = sf::RectangleShape(sf::Vector2f(100.0f, 200.0f));
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(0, 0);

    //shape.setPosition(WIDTH / 2, HEIGHT / 2);
}

sf::RectangleShape MainScene::GetSceneElements()
{
    sf::RectangleShape shape = sf::RectangleShape(sf::Vector2f(100.0f, 200.0f));
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(0, 0);

    return shape;
}
