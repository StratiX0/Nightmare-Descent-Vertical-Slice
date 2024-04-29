#include "Background.h"

void Background::SetPath(const std::string& _path)
{
    path = _path;

    if (!texture.loadFromFile(path))
    {
        return;
    }

    if (!image.loadFromFile(path))
    {
        return;
    }

    sprite.setTexture(texture);
}

void Background::SetSize(sf::RenderWindow* window)
{
    if (texture.getSize().x > 0 && texture.getSize().y > 0)
    {
        float scaleX = static_cast<float>(window->getSize().x) / texture.getSize().x;
        float scaleY = static_cast<float>(window->getSize().y) / texture.getSize().y;
        sprite.setScale(scaleX, scaleY);
    }
}
