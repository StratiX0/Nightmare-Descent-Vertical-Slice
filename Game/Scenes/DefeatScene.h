#pragma once
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Scene.h"
#include "Background.h"
#include <SFML/Audio.hpp>


class DefeatScene final : public Scene
{
public:

    //sf::SoundBuffer buffer;
    //sf::Sound sound;

    // Cree les objets de la scene.
    DefeatScene() : Scene("DefeatScene")
    {
        // Chargez le son à partir d'un fichier
        //if (!buffer.loadFromFile("Assets/defeat.ogg")) {
            // Gérez l'erreur si le fichier ne peut pas être chargé
        //}

        // Créez un objet sf::Sound pour jouer le son
        //sound.setBuffer(buffer);

        // Jouez le son
        //sound.play();
        // Cree les arriere-plans de la scene.
        CreateBackgrounds("Assets/Background2.png");

        /////////////////////////////////
        //    Creer un objet au sol    //
        /////////////////////////////////
        CreateEnvironment("Defeat", "logo", "Assets/Defeat.png", Maths::Vector2f(650.0f, 350.0f), Maths::Vector2f(654.0f, 336.0f));
    }
};

