#include "Background.h"

// Methode pour definir le chemin d'acces a l'image de l'arriere-plan.
void Background::SetPath(const std::string& _path, int _id)
{
    // Met a jour le chemin et l'ID de l'arriere-plan.
    path = _path;
    id = _id;

    // Charge la texture a partir du fichier. Si le chargement echoue, retourne immediatement.
    if (!texture.loadFromFile(path))
    {
        return;
    }

    // Charge l'image a partir du fichier. Si le chargement echoue, retourne immediatement.
    if (!image.loadFromFile(path))
    {
        return;
    }

    // Met a jour le sprite de l'arriere-plan avec la nouvelle texture.
    sprite.setTexture(texture);
}

// Methode pour definir la taille de l'arriere-plan.
void Background::SetSize(float _width, float _height)
{

    // Calcule l'echelle en fonction de la taille souhaitee et de la taille de la texture.
    float scaleX = static_cast<float>(_width) / texture.getSize().x;
    float scaleY = static_cast<float>(_height) / texture.getSize().y;

    // Met a jour l'echelle du sprite de l'arriere-plan.
    sprite.setScale(scaleX, scaleY);
}

// Methode pour deplacer l'arriere-plan.
void Background::MoveBackground(int _id, float x, float y)
{

    // Si l'ID correspond a l'ID de l'arriere-plan, deplace le sprite de l'arriere-plan.
    if (id == _id)
    {
        sprite.move(x, y);
    }
}
