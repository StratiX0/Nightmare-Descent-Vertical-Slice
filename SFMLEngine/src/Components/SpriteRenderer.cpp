#include "Components/SpriteRenderer.h"
#include "Components/RectangleShapeRenderer.h"
#include <SFML/Graphics/Texture.hpp>

SpriteRenderer::SpriteRenderer()
{
    // Initialisation du sprite et de la texture.
    sprite = new sf::Sprite();
    texture = new sf::Texture();

}

SpriteRenderer::~SpriteRenderer()
{
    // Suppression du sprite et de la texture.
    delete sprite;
    delete texture;
}

void SpriteRenderer::SetTexture(sf::Texture* _texture)
{
    texture = _texture;
    sprite->setTexture(*texture);
}

void SpriteRenderer::LoadTexture(const std::string& _texturePath)
{
    if (texture->loadFromFile(_texturePath))
    {
        sprite->setTexture(*texture);
    }
}

void SpriteRenderer::Update(float _delta_time)
{
    GameObject* owner = GetOwner();
    if (owner != nullptr)
    {
        if (sprite != nullptr)
        {
            sprite->setPosition(owner->GetPosition().x, owner->GetPosition().y);
        }
    }
}

void SpriteRenderer::Render(sf::RenderWindow* _window)
{
    _window->draw(*sprite);
}
