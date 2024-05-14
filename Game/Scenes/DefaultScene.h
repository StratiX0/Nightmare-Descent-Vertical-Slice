#pragma once

#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Background.h"

// La classe DefaultScene herite de la classe Scene
// et represente la scene par defaut de votre jeu.
class DefaultScene final : public Scene
{
public:
    // Constructeur de la classe DefaultScene.
    // Cree les objets de la scene.
    DefaultScene() : Scene("DefaultScene")
    {
        // Cree les arriere-plans de la scene.
        CreateBackgrounds("Assets/Background2.png");

        /////////////////////////////////
        //    Creer l'entite joueur    //
        /////////////////////////////////

        GameObject* player = CreateInGameObject("Player", "Player", Maths::Vector2f(1600.0f / 2 - 40.0f / 2, -500.0f), Maths::Vector2f(60.f, 60.0f), 1.0f, sf::Color::White);
        player->CreateComponent<Player>();

        //////////////////////////////////
        //  Creer des entites ennemies  //
        //////////////////////////////////

        GameObject* enemy = CreateInGameObject("Enemy1", "Enemy", Maths::Vector2f(2000.0f, -500.0f), Maths::Vector2f(60.f, 60.0f), 1.0f, sf::Color::White);
        enemy->CreateComponent<Enemy>();

        GameObject* enemy2 = CreateInGameObject("Thrower", "Enemy", Maths::Vector2f(1500.0f, -500.0f), Maths::Vector2f(60.f, 60.0f), 1.0f, sf::Color::White);
        enemy2->CreateComponent<Enemy>();

        GameObject* enemy3 = CreateInGameObject("Thrower", "Enemy", Maths::Vector2f(3500.0f, -500.0f), Maths::Vector2f(60.f, 60.0f), 1.0f, sf::Color::White);
        enemy3->CreateComponent<Enemy>();

        GameObject* enemy4 = CreateInGameObject("Thrower", "Enemy", Maths::Vector2f(3200.0f, -500.0f), Maths::Vector2f(60.f, 60.0f), 1.0f, sf::Color::White);
        enemy4->CreateComponent<Enemy>();

        /////////////////////////////////
		//    Creer un objet au sol    //
		/////////////////////////////////
        CreateInGameObject("Ground", "Object", Maths::Vector2f(400.0f, 0.0f), Maths::Vector2f(100.f, 900.0f), 1.0f, sf::Color::Transparent);
        CreateInGameObject("Ground", "Object", Maths::Vector2f(500.0f, 800.0f), Maths::Vector2f(1600.f, 100.0f), 1.0f, sf::Color::Transparent);
        CreateInGameObject("Ground", "Object", Maths::Vector2f(2350.0f, 800.0f), Maths::Vector2f(1600.f, 100.0f), 1.0f, sf::Color::Transparent);
        CreateInGameObject("Ground", "Object", Maths::Vector2f(3950.0f, 500.0f), Maths::Vector2f(400.f, 900.0f), 1.0f, sf::Color::Transparent);


        //////////////////////////////////
		// Creer un objet de plateforme //
		//////////////////////////////////
        CreateInGameObject("Platform", "Object", Maths::Vector2f(1250.f, 600.0f), Maths::Vector2f(300.f, 40.0f), 1.0f, sf::Color::Green);
        CreateInGameObject("Platform", "Object", Maths::Vector2f(2600.f, 600.0f), Maths::Vector2f(400.f, 40.0f), 1.0f, sf::Color::Green);
        CreateInGameObject("Platform", "Object", Maths::Vector2f(3300.f, 600.0f), Maths::Vector2f(400.f, 40.0f), 1.0f, sf::Color::Green);

    }
};
