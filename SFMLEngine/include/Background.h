#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Maths/Vector2.h"

class Background
{
public:
    Background() = default;
    ~Background() = default;

	void SetId(int _id) { id = _id; }
	int GetId() const { return id; }

    void SetPath(const std::string& _path, int _id);
    void SetSize(float _width, float _height);
    sf::Vector2u GetSize() const { return texture.getSize(); }

	void MoveBackground(int _id, float x, float y);

    void SetPosition(float x, float y) { sprite.setPosition(x, y); }
    sf::Vector2f GetPosition() const { return sprite.getPosition(); }

    const std::string& GetPath() const { return path; }

    sf::Sprite GetSprite() const { return sprite; }
    const sf::Image& GetImage() const { return image; }

private:
    std::string path;
    sf::Texture texture;
	sf::Sprite sprite;
    sf::Image image;
    sf::Vector2f position;
	int id = 0;
};
