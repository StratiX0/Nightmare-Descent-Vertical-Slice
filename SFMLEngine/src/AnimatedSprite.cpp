#include "AnimatedSprite.h"
#include "Components/RectangleShapeRenderer.h"

AnimatedSpriteComponent::AnimatedSpriteComponent()
    : frameCount(0), frameTime(0.0f), currentFrame(0), currentTime(0.0f)
{
    sprite = new sf::Sprite();
    texture = new sf::Texture();
}


AnimatedSpriteComponent::~AnimatedSpriteComponent()
{
    delete sprite;
    sprite = nullptr;
    delete texture;
    texture = nullptr;
}

void AnimatedSpriteComponent::SetTexture(sf::Texture* _texture)
{
    texture = _texture;
    sprite->setTexture(*texture);

    // Définir l'origine du sprite à son centre
	defaultOriginX = texture->getSize().x / 2.0f;
	defaultOriginY = texture->getSize().y;
    sprite->setOrigin(defaultOriginX, defaultOriginY);
}

void AnimatedSpriteComponent::LoadTexture(const std::string& texturePath)
{
    if (!texture->loadFromFile(texturePath))
    {
        // Handle error
    }
    sprite->setTexture(*texture);
}

void AnimatedSpriteComponent::SetTextureRect(int _left, int _top, int _width, int _height)
{
    sprite->setTextureRect(sf::IntRect(_left, _top, _width, _height));
}

void AnimatedSpriteComponent::SetDirection(MovementDirection _direction)
{
    direction = _direction;
    if (direction == MovementDirection::Right)
    {
        sprite->setScale(defaultScaleX, defaultScaleY);
        sprite->setOrigin(defaultOriginX, defaultOriginY);
    }
    else if (direction == MovementDirection::Left)
    {
        sprite->setScale(-defaultScaleX, defaultScaleY);
        sf::IntRect rect = sprite->getTextureRect();
        sprite->setOrigin(rect.width, defaultOriginY);
    }
}

void AnimatedSpriteComponent::Update(float deltaTime)
{
    currentTime += deltaTime;
    if (currentTime >= frameTime)
    {
        currentFrame = (currentFrame + 1) % frameCount;
        if (frameCount > 0 && texture != nullptr) {
            sprite->setTextureRect(sf::IntRect(currentFrame * texture->getSize().x / frameCount, 0, texture->getSize().x / frameCount, texture->getSize().y));
        }
        currentTime -= frameTime;
    }
    GameObject* owner = GetOwner();
    if (owner != nullptr) {
        // Mettez à jour la position du sprite pour qu'il soit centré sur le gameObject
        Maths::Vector2f gameObjectSize = owner->GetComponent<RectangleShapeRenderer>()->GetSize();
        sprite->setPosition(owner->GetPosition().x, owner->GetPosition().y);
    }
}

void AnimatedSpriteComponent::Render(sf::RenderWindow* window)
{
    window->draw(*sprite);
}
