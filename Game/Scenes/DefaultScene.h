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
		//    Creer un objet au sol    //
		/////////////////////////////////
        CreateObject("Ground", "Object", "Assets/Ground.png", Maths::Vector2f(-500.0f, 0.0f), Maths::Vector2f(1000.f, 900.0f), sf::Color::Transparent, true);
        CreateObject("Ground", "Object", "Assets/Ground.png", Maths::Vector2f(500.0f, 800.0f), Maths::Vector2f(1600.f, 100.0f), sf::Color::Transparent, true);
        CreateObject("Ground", "Object", "Assets/Ground.png", Maths::Vector2f(2350.0f, 800.0f), Maths::Vector2f(1600.f, 100.0f), sf::Color::Transparent, true);
        CreateObject("Ground", "Object", "Assets/Ground.png", Maths::Vector2f(3950.0f, 500.0f), Maths::Vector2f(400.f, 900.0f), sf::Color::Transparent, true);
        CreateObject("Ground", "Object", "Assets/Ground.png", Maths::Vector2f(4700.0f, 500.0f), Maths::Vector2f(400.f, 900.0f), sf::Color::Transparent, true);
        CreateObject("Ground", "Object", "Assets/Ground.png", Maths::Vector2f(5100.0f, 600.0f), Maths::Vector2f(200.f, 900.0f), sf::Color::Transparent, true);
        CreateObject("Ground", "Object", "Assets/Ground.png", Maths::Vector2f(5300.0f, 700.0f), Maths::Vector2f(800.f, 900.0f), sf::Color::Transparent, true);
        CreateObject("Ground", "Object", "Assets/Ground.png", Maths::Vector2f(6700.0f, 700.0f), Maths::Vector2f(600.f, 900.0f), sf::Color::Transparent, true);
        CreateObject("Ground", "Object", "Assets/Ground.png", Maths::Vector2f(7950.0f, 700.0f), Maths::Vector2f(600.f, 900.0f), sf::Color::Transparent, true);
        CreateObject("Ground", "Object", "Assets/Ground.png", Maths::Vector2f(8550.0f, 600.0f), Maths::Vector2f(400.f, 900.0f), sf::Color::Transparent, true);
        CreateObject("Ground", "Object", "Assets/Ground.png", Maths::Vector2f(9300.0f, 600.0f), Maths::Vector2f(400.f, 900.0f), sf::Color::Transparent, true);

        //////////////////////////////////
		// Creer un objet de plateforme //
		//////////////////////////////////
        CreateObject("Platform", "Object", "Assets/Platform.png", Maths::Vector2f(1250.f, 600.0f), Maths::Vector2f(300.f, 40.0f), sf::Color::Transparent, true);
        CreateObject("Platform", "Object", "Assets/Platform.png", Maths::Vector2f(2600.f, 600.0f), Maths::Vector2f(400.f, 40.0f), sf::Color::Transparent, true);
        CreateObject("Platform", "Object", "Assets/Platform.png", Maths::Vector2f(3300.f, 600.0f), Maths::Vector2f(400.f, 40.0f), sf::Color::Transparent, true);
        CreateObject("Platform", "Object", "Assets/Platform.png", Maths::Vector2f(5300.f, 350.0f), Maths::Vector2f(250.f, 40.0f), sf::Color::Transparent, true);
        CreateObject("Platform", "Object", "Assets/Platform.png", Maths::Vector2f(5900.f, 350.0f), Maths::Vector2f(300.f, 40.0f), sf::Color::Transparent, true);
        CreateObject("Platform", "Object", "Assets/Platform.png", Maths::Vector2f(6550.f, 350.0f), Maths::Vector2f(250.f, 40.0f), sf::Color::Transparent, true);
        CreateObject("Platform", "Object", "Assets/Platform.png", Maths::Vector2f(7500.f, 525.0f), Maths::Vector2f(250.f, 40.0f), sf::Color::Transparent, true);

		//////////////////////////////////
		// Creer un objet de decoration //
		//////////////////////////////////

		CreateEnvironment("Tree", "Environment", "Assets/DarkTree.png", Maths::Vector2f(700.0f, 600.0f), Maths::Vector2f(100.0f, 200.0f));
        CreateEnvironment("Rock", "Environment", "Assets/Bush.png", Maths::Vector2f(1000.0f, 750.0f), Maths::Vector2f(50.0f, 50.0f));
        CreateEnvironment("Tree", "Environment", "Assets/DeadTree.png", Maths::Vector2f(1700.0f, 600.0f), Maths::Vector2f(100.0f, 200.0f));
        CreateEnvironment("Tombstone", "Environment", "Assets/Tombstone.png", Maths::Vector2f(1400.0f, 550.0f), Maths::Vector2f(50.0f, 50.0f));
        CreateEnvironment("Tombstone", "Environment", "Assets/Tombstone3.png", Maths::Vector2f(2450.0f, 600.0f), Maths::Vector2f(100.0f, 200.0f));

        /////////////////////////////////
        //    Creer l'entite joueur    //
        /////////////////////////////////

        GameObject* player = CreateInGameObject("Player", "Player", Maths::Vector2f(1600.0f / 2 - 40.0f / 2, -500.0f), Maths::Vector2f(80.f, 80.0f), 1.0f, sf::Color::Transparent);
        player->CreateComponent<Player>();

        //////////////////////////////////
        //  Creer des entites ennemies  //
        //////////////////////////////////

        Maths::Vector2f enemySize = Maths::Vector2f(80.f, 80.0f);

        GameObject* enemy = CreateInGameObject("Wanderer", "Enemy", Maths::Vector2f(2000.0f, -500.0f), enemySize, 1.0f, sf::Color::White);
        enemy->CreateComponent<Enemy>();

        GameObject* enemy2 = CreateInGameObject("Thrower", "Enemy", Maths::Vector2f(1500.0f, -500.0f), enemySize, 1.0f, sf::Color::White);
        enemy2->CreateComponent<Enemy>();

        GameObject* enemy3 = CreateInGameObject("Thrower", "Enemy", Maths::Vector2f(3400.0f, -500.0f), enemySize, 1.0f, sf::Color::White);
        enemy3->CreateComponent<Enemy>();

        GameObject* enemy4 = CreateInGameObject("Wanderer", "Enemy", Maths::Vector2f(3500.0f, -500.0f), enemySize, 1.0f, sf::Color::White);
        enemy4->CreateComponent<Enemy>();

        GameObject* enemy5 = CreateInGameObject("Wanderer", "Enemy", Maths::Vector2f(5800.0f, -500.0f), enemySize, 1.0f, sf::Color::White);
        enemy5->CreateComponent<Enemy>();

        GameObject* enemy6 = CreateInGameObject("Wanderer", "Enemy", Maths::Vector2f(6100.0f, -500.0f), enemySize, 1.0f, sf::Color::White);
        enemy6->CreateComponent<Enemy>();

        GameObject* enemy7 = CreateInGameObject("Wanderer", "Enemy", Maths::Vector2f(7100.0f, -500.0f), enemySize, 1.0f, sf::Color::White);
        enemy7->CreateComponent<Enemy>();

        GameObject* enemy8 = CreateInGameObject("Wanderer", "Enemy", Maths::Vector2f(8200.0f, -500.0f), enemySize, 1.0f, sf::Color::White);
        enemy8->CreateComponent<Enemy>();

    }
};
