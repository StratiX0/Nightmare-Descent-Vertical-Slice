#include "AnimatedSprite.h"
#include "Components/RectangleShapeRenderer.h"

// Constructeur de la classe AnimatedSpriteComponent. Initialise les variables membres et cree les sprites et textures.
AnimatedSpriteComponent::AnimatedSpriteComponent()
    : frameCount(0), frameTime(0.0f), currentFrame(0), currentTime(0.0f)
{
    sprite = new sf::Sprite();
    texture = new sf::Texture();

}

// Destructeur de la classe AnimatedSpriteComponent. Supprime les sprites et textures.
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

    // Calculez la largeur et la hauteur de chaque frame en fonction de la taille de la texture et du nombre de frames.
    frameWidth = texture->getSize().x / frameCount;
    frameHeight = texture->getSize().y;

    sprite->setTexture(*texture);
    sprite->setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));
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
    // Mettre a jour l'origine apres avoir defini le rectangle de texture
    defaultOriginX = static_cast<float>(sprite->getTextureRect().width / 2.0f);
    defaultOriginY = static_cast<float>(0);
    sprite->setOrigin(defaultOriginX, defaultOriginY);
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
        float originX = static_cast<float>(texture->getSize().x / frameCount);
        sprite->setOrigin(originX, defaultOriginY);
    }
}

// Recupere le chemin du fichier de texture pour un etat donne.
std::string AnimatedSpriteComponent::GetStateFilePath(SpriteState state) const
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
int AnimatedSpriteComponent::GetStateFrameCount(SpriteState state) const
{
    if (stateFrameCounts.count(state) > 0) {
        return stateFrameCounts.at(state);
    }
    else {
        // Handle error: state not found in stateFrameCounts
        return 0;
    }
}

// Fait clignoter le sprite en alternant son opacité.
void AnimatedSpriteComponent::Blink(float blinkTime, float deltaTime)
{
    static float currentTime = 0.0f;
    static bool isRed = false;
    currentTime += deltaTime;
    sf::Color color = sprite->getColor();

    if (currentTime > blinkTime)
    {
        if (isRed) {
            sprite->setColor(sf::Color::White); // Reset to original color
            isRed = false;
        }
        else {
            color.r = 255; // Set red color
            color.g = 0; // Remove green color
            color.b = 0; // Remove blue color
            sprite->setColor(color);
            isRed = true;
        }
        currentTime = 0.0f;
    }
}


// Met a jour le sprite anime.
void AnimatedSpriteComponent::Update(float deltaTime)
{
    // Verifier si l'etat a change
    if (state != lastState) {
        // Charge la texture pour l'etat actuel
        LoadTexture(GetStateFilePath(state));
        // Met a jour frameCount pour l'etat actuel
        SetFrameCount(GetStateFrameCount(state));
        // Met a jour lastState
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
    if (owner != nullptr) 
    {
        RectangleShapeRenderer* renderer = owner->GetComponent<RectangleShapeRenderer>();
        if (renderer != nullptr) 
        {
            Maths::Vector2f gameObjectSize = renderer->GetSize();
            if (sprite != nullptr) 
            {
                sprite->setPosition(owner->GetPosition().x, owner->GetPosition().y);
            }
        }
    }
}

// Dessine le sprite sur la fenêtre donnee.
void AnimatedSpriteComponent::Render(sf::RenderWindow* window)
{
    window->draw(*sprite);
}
