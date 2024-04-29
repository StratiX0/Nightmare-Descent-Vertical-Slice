#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Background
{
public:
    Background() = default;
    ~Background() = default;

    void SetPath(const std::string& _path);
	void SetSize(sf::RenderWindow* window);

    const std::string& GetPath() const { return path; }

    // Ajoutez ces méthodes pour obtenir le sprite et l'image
    const sf::Sprite& GetSprite() const { return sprite; }
    const sf::Image& GetImage() const { return image; }

private:
    std::string path;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Image image;
};
