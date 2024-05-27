#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>

// La classe AnimatedSpriteComponent herite de la classe Component et represente un sprite anime dans le jeu.
class AnimatedSpriteComponent : public Component
{
public:

    // Enumeration representant les directions de mouvement possibles.
    enum MovementDirection
    {
        Left,
        Right,
        Up,
        Down
    };

    // Enumeration representant les etats possibles du sprite du joueur.
    enum class SpriteState
    {
        Idle,
        Running,
        Moving,
        Jump
    };

    // Constructeur et destructeur.
    AnimatedSpriteComponent();
    ~AnimatedSpriteComponent() override;

    // Methodes pour gerer la texture du sprite.
    void SetTexture(sf::Texture* _texture);
    void LoadTexture(const std::string& _texturePath);

    // Methodes pour gerer le nombre de frames de l'animation.
    void SetFrameCount(int _frameCount) { frameCount = _frameCount; }
    int GetFrameCount() const { return frameCount; }

    // Methodes pour acceder au sprite et a la texture.
    sf::Sprite* GetSprite() { return sprite; }
    sf::Texture* GetTexture() { return texture; }

    // Methodes pour gerer le temps entre les frames.
    void SetFrameTime(float _frameTime) { frameTime = _frameTime; }

    // Methodes pour gérer la frame actuelle.
    void SetCurrentFrame(int _currentFrame) { currentFrame = _currentFrame; }

    // Methodes pour gerer le temps ecoule depuis le debut de l'animation.
    void SetCurrentTime(float _currentTime) { currentTime = _currentTime; }

    // Methode pour definir le rectangle de texture du sprite.
    void SetTextureRect(int _left, int _top, int _width, int _height);

    // Methodes pour gerer la direction du mouvement.
    void SetDirection(MovementDirection _direction);
    MovementDirection GetDirection() const { return direction; }

    // Methodes pour gerer l'echelle par defaut du sprite.
    void SetDefaultScale(float _scaleX, float _scaleY) { defaultScaleX = _scaleX; defaultScaleY = _scaleY; }

    // Methodes pour mettre a jour et dessiner le sprite.
    void Update(float deltaTime) override;
    void Render(sf::RenderWindow* window) override;

    // Variables representant la direction et l'etat actuels du sprite.
    MovementDirection direction;
    SpriteState state;
    SpriteState lastState;

    // Methodes pour gerer l'etat du sprite.
    void SetState(SpriteState _state) { state = _state; }
    void SetStateFrameCount(SpriteState state, int frameCount) { stateFrameCounts[state] = frameCount; SetFrameCount(frameCount); }
    int GetStateFrameCount(SpriteState state) const;
    void SetStateFilePath(SpriteState state, const std::string& filePath) { stateFilePaths[state] = filePath; }
    std::string GetStateFilePath(SpriteState state) const;

    void Blink(float blinkTime, float deltaTime);

private:

    // Maps pour stocker le nombre de frames et le chemin du fichier pour chaque etat.
    std::map<SpriteState, int> stateFrameCounts;
    std::map<SpriteState, std::string> stateFilePaths;

    // Pointeur vers le sprite et la texture.
    sf::Sprite* sprite;
    sf::Texture* texture;

    // Variables pour stocker le nombre de frames, le temps entre les frames, la frame actuelle et le temps ecoule depuis le debut de l'animation.
    int frameCount;
    float frameTime;
    int currentFrame;
    float currentTime;

    // Variables pour stocker l'origine et l'echelle par defaut du sprite.
    float defaultOriginX, defaultOriginY;
    float defaultScaleX, defaultScaleY;

	// Variables pour stocker la largeur et la hauteur du sprite.
    int frameWidth;
    int frameHeight;
};
