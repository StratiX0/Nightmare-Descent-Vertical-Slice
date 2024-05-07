#include "AnimatedSprite.h"
#include "Components/RectangleShapeRenderer.h"

// Constructeur de la classe AnimatedSpriteComponent.
// Initialise les variables membres et cree les sprites et textures.
AnimatedSpriteComponent::AnimatedSpriteComponent()
    : frameCount(0), frameTime(0.0f), currentFrame(1), currentTime(0.0f), lastState(PlayerSpriteState::Idle)
{
    sprite = new sf::Sprite();
    texture = new sf::Texture();
    stateFilePaths[PlayerSpriteState::Idle] = "Assets/Idle.png";
    stateFilePaths[PlayerSpriteState::Running] = "Assets/Run.png";
}

// Destructeur de la classe AnimatedSpriteComponent.
// Supprime les sprites et textures.
AnimatedSpriteComponent::~AnimatedSpriteComponent()
{
    delete sprite;
    sprite = nullptr;
    delete texture;
    texture = nullptr;
}

// Definit la texture du sprite.
void AnimatedSpriteComponent::SetTexture(sf::Texture* _texture)
{
    texture = _texture;
    sprite->setTexture(*texture);

    // Definir l'origine du sprite a son centre
    defaultOriginX = static_cast<float>(texture->getSize().x / 2.0f);
    defaultOriginY = static_cast<float>(texture->getSize().y / 2.0f);
    sprite->setOrigin(defaultOriginX, defaultOriginY);
}

// Charge une texture a partir d'un fichier.
void AnimatedSpriteComponent::LoadTexture(const std::string& texturePath)
{
    if (!texture->loadFromFile(texturePath))
    {
        // Handle error
    }
    sprite->setTexture(*texture);
}

// Definit le rectangle de texture du sprite.
void AnimatedSpriteComponent::SetTextureRect(int _left, int _top, int _width, int _height)
{
    sprite->setTextureRect(sf::IntRect(_left, _top, _width, _height));
}

// Definit la direction du mouvement du sprite.
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
        sprite->setOrigin(static_cast<float>(rect.width), defaultOriginY);
    }
}

// Recupere le chemin du fichier de texture pour un etat donne.
std::string AnimatedSpriteComponent::GetStateFilePath(PlayerSpriteState state) const
{
    if (stateFilePaths.count(state) > 0) {
        return stateFilePaths.at(state);
    }
    else {
        // Handle error: state not found in stateFilePaths
        return "";
    }
}

// Recupere le nombre de frames pour un etat donne.
int AnimatedSpriteComponent::GetStateFrameCount(PlayerSpriteState state) const
{
    if (stateFrameCounts.count(state) > 0) {
        return stateFrameCounts.at(state);
    }
    else {
        // Handle error: state not found in stateFrameCounts
        return 0;
    }
}

// Met a jour le sprite anime.
void AnimatedSpriteComponent::Update(float deltaTime)
{
    // Verifier si l'etat a change
    if (state != lastState) {
        // Charger la texture pour l'etat actuel
        LoadTexture(GetStateFilePath(state));
        // Mettre a jour frameCount pour l'etat actuel
        SetFrameCount(GetStateFrameCount(state));
        // Mettre a jour lastState
        lastState = state;
    }
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
        // Mettez a jour la position du sprite pour qu'il soit centre sur le gameObject
        Maths::Vector2f gameObjectSize = owner->GetComponent<RectangleShapeRenderer>()->GetSize();
        sprite->setPosition(owner->GetPosition().x, owner->GetPosition().y);
    }
}

// Dessine le sprite sur la fenêtre donnee.
void AnimatedSpriteComponent::Render(sf::RenderWindow* window)
{
    window->draw(*sprite);
}
