#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>

class AnimatedSpriteComponent : public Component
{
public:

    enum MovementDirection
    {
        Left,
        Right,
        Up,
        Down
    };

    enum class PlayerSpriteState
    {
        Idle = 15,      // 15 frames for Idle
        Running = 8,   // 8 frames for Running
    };


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
    void SetDirection(MovementDirection _direction);
	MovementDirection GetDirection() const { return direction; }
	void SetDefaultScale(float _scaleX, float _scaleY) { defaultScaleX = _scaleX; defaultScaleY = _scaleY; }

    void Update(float deltaTime) override;
    void Render(sf::RenderWindow* window) override;

    MovementDirection direction;
    PlayerSpriteState state;
    PlayerSpriteState lastState;

	void SetState(PlayerSpriteState _state) { state = _state; }
    void SetStateFrameCount(PlayerSpriteState state, int frameCount) { stateFrameCounts[state] = frameCount; SetFrameCount(frameCount); }
    int GetStateFrameCount(PlayerSpriteState state) const;
    void SetStateFilePath(PlayerSpriteState state, const std::string& filePath) { stateFilePaths[state] = filePath; }
    std::string GetStateFilePath(PlayerSpriteState state) const;

private:

    std::map<PlayerSpriteState, int> stateFrameCounts;
    std::map<PlayerSpriteState, std::string> stateFilePaths;
    sf::Sprite* sprite;
    sf::Texture* texture;
    int frameCount;
    float frameTime;
    int currentFrame;
    float currentTime;
	float defaultOriginX, defaultOriginY;
	float defaultScaleX, defaultScaleY;

};