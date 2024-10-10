#pragma once
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Scene.h"
#include "Music.h"
#include "Background.h"
#include <SFML/Audio.hpp>


class DefeatScene final : public Scene
{
public:

    // Cree les objets de la scene.
    DefeatScene() : Scene("DefeatScene")
    {
        //CreateGameObject("Musique", "Victoire", 1)->CreateComponent<Music>();

        // Cree les arriere-plans de la scene.
        CreateBackgrounds("Assets/Background2.png");

        /////////////////////////////////
        //    Creer un objet au sol    //
        /////////////////////////////////
        CreateEnvironment("Defeat", "logo", "Assets/Defeat.png", Maths::Vector2f(650.0f, 350.0f), Maths::Vector2f(654.0f, 336.0f));
    }
};

