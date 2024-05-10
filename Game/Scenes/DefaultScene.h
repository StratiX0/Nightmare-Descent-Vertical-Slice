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

        GameObject* player = CreateInGameObject("Player", "Player", Maths::Vector2f(1600.0f / 2 - 40.0f / 2, -500.0f), Maths::Vector2f(80.f, 80.0f), 1.0f, sf::Color::White);
        player->CreateComponent<Player>();

        //////////////////////////////////
        //  Creer des entites ennemies  //
        //////////////////////////////////

        GameObject* enemy = CreateInGameObject("Enemy1", "Enemy", Maths::Vector2f(900.0f, -500.0f), Maths::Vector2f(80.f, 80.0f), 1.0f, sf::Color::White);
        enemy->CreateComponent<Enemy>();

        GameObject* enemy2 = CreateInGameObject("Thrower", "Enemy", Maths::Vector2f(1000.0f, -500.0f), Maths::Vector2f(80.f, 80.0f), 1.0f, sf::Color::White);
        enemy2->CreateComponent<Enemy>();

        /////////////////////////////////
		//    Creer un objet au sol    //
		/////////////////////////////////
        CreateInGameObject("Ground", "Object", Maths::Vector2f(50.0f, 700.0f), Maths::Vector2f(100.f, 900.0f), 1.0f, sf::Color::Transparent);
        CreateInGameObject("Ground", "Object", Maths::Vector2f(50.0f, 800.0f), Maths::Vector2f(1600.f, 100.0f), 1.0f, sf::Color::Transparent);
        CreateInGameObject("Ground", "Object", Maths::Vector2f(1850.0f, 800.0f), Maths::Vector2f(1600.f, 100.0f), 1.0f, sf::Color::Transparent);

        //////////////////////////////////
		// Creer un objet de plateforme //
		//////////////////////////////////
        CreateInGameObject("Platform", "Object", Maths::Vector2f(350.f, 650.0f), Maths::Vector2f(300.f, 50.0f), 1.0f, sf::Color::Green);
    }
};
