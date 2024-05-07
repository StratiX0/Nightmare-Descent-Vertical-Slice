#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Maths/Vector2.h"

// La classe Background represente un arriere-plan dans votre jeu.
class Background
{
public:

    // Constructeur et destructeur par defaut de la classe Background.
    Background() = default;
    ~Background() = default;

    // Methodes pour definir et obtenir l'ID de l'arriere-plan.
    void SetId(int _id) { id = _id; }
    int GetId() const { return id; }

    // Methode pour definir le chemin d'acces a l'image de l'arriere-plan.
    void SetPath(const std::string& _path, int _id);

    // Methode pour definir la taille de l'arriere-plan.
    void SetSize(float _width, float _height);

    // Methode pour obtenir la taille de l'arriere-plan.
    sf::Vector2u GetSize() const { return texture.getSize(); }

    // Methode pour deplacer l'arriere-plan.
    void MoveBackground(int _id, float x, float y);

    // Methodes pour definir et obtenir la position de l'arriere-plan.
    void SetPosition(float x, float y) { sprite.setPosition(x, y); }
    sf::Vector2f GetPosition() const { return sprite.getPosition(); }

    // Methode pour obtenir le chemin d'acces a l'image de l'arriere-plan.
    const std::string& GetPath() const { return path; }

    // Methodes pour obtenir le sprite et l'image de l'arriere-plan.
    sf::Sprite GetSprite() const { return sprite; }
    const sf::Image& GetImage() const { return image; }

private:

    // Variables pour stocker le chemin d'acces a l'image, la texture, le sprite, l'image, la position et l'ID de l'arriere-plan.
    std::string path;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Image image;
    sf::Vector2f position;
    int id = 0;
};
