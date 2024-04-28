#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>

class AnimatedSpriteComponent : public Component
{
public:
    AnimatedSpriteComponent();
    ~AnimatedSpriteComponent() override;

    void SetTexture(sf::Texture* _texture);
    void LoadTexture(const std::string& _texturePath);
    void SetFrameCount(int _frameCount) { frameCount = _frameCount; }
    sf::Sprite* GetSprite() { return sprite; }
    sf::Texture* GetTexture() { return texture; }
    int GetFrameCount() const { return frameCount; }
    void SetFrameTime(float _frameTime) { frameTime = _frameTime; }
    void SetCurrentFrame(int _currentFrame) { currentFrame = _currentFrame; }
    void SetCurrentTime(float _currentTime) { currentTime = _currentTime; }
    void SetTextureRect(int _left, int _top, int _width, int _height);

    void Update(float deltaTime) override;
    void Render(sf::RenderWindow* window) override;

private:
    sf::Sprite* sprite;
    sf::Texture* texture;
    int frameCount;
    float frameTime;
    int currentFrame;
    float currentTime;
};