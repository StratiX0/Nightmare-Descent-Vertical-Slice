#pragma once

#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Scene.h"
#include "Background.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>


class MainMenuScene : public Scene
{
public:
    MainMenuScene() : Scene("MainMenuScene")
    {
        CreateBackgrounds("Assets/Background2.png");
        // Chargez une police à partir d'un fichier
        sf::Font font;
        if (!font.loadFromFile("Assets/arial.ttf")) {
            // Gérez l'erreur de chargement de la police ici
        }

        // Créez le texte "Jouer"
        sf::Text playText;
        playText.setFont(font);
        playText.setString("Jouer");
        playText.setCharacterSize(24); // en pixels
        playText.setFillColor(sf::Color::White);
        playText.setPosition(900.0f, 200.0f);

        // Créez le texte "Options"
        sf::Text optionsText;
        optionsText.setFont(font);
        optionsText.setString("Options");
        optionsText.setCharacterSize(24); // en pixels
        optionsText.setFillColor(sf::Color::White);
        optionsText.setPosition(900.0f, 400.0f);

        // Créez le texte "Quitter"
        sf::Text quitText;
        quitText.setFont(font);
        quitText.setString("Quitter");
        quitText.setCharacterSize(24); // en pixels
        quitText.setFillColor(sf::Color::White);
        quitText.setPosition(900.0f, 600.0f);

		// Afficher le texte à l'écran
    }
};


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
        CreateObject("Ground", "Object", "Assets/Ground.png", Maths::Vector2f(-500.0f, -1000.0f), Maths::Vector2f(1000.f, 3000.0f), sf::Color::Transparent, true);
        CreateObject("Ground", "Object", "Assets/Ground.png", Maths::Vector2f(500.0f, 900.0f), Maths::Vector2f(1600.f, 500.0f), sf::Color::Transparent, true);
        CreateObject("Ground", "Object", "Assets/Ground.png", Maths::Vector2f(2350.0f, 900.0f), Maths::Vector2f(1600.f, 500.0f), sf::Color::Transparent, true);
        CreateObject("Ground", "Object", "Assets/Ground.png", Maths::Vector2f(3950.0f, 600.0f), Maths::Vector2f(400.f, 900.0f), sf::Color::Transparent, true);
        CreateObject("Ground", "Object", "Assets/Ground.png", Maths::Vector2f(4700.0f, 600.0f), Maths::Vector2f(400.f, 900.0f), sf::Color::Transparent, true);
        CreateObject("Ground", "Object", "Assets/Ground.png", Maths::Vector2f(5100.0f, 700.0f), Maths::Vector2f(200.f, 900.0f), sf::Color::Transparent, true);
        CreateObject("Ground", "Object", "Assets/Ground.png", Maths::Vector2f(5300.0f, 800.0f), Maths::Vector2f(800.f, 900.0f), sf::Color::Transparent, true);
        CreateObject("Ground", "Object", "Assets/Ground.png", Maths::Vector2f(6700.0f, 800.0f), Maths::Vector2f(600.f, 900.0f), sf::Color::Transparent, true);
        CreateObject("Ground", "Object", "Assets/Ground.png", Maths::Vector2f(7950.0f, 800.0f), Maths::Vector2f(600.f, 900.0f), sf::Color::Transparent, true);
        CreateObject("Ground", "Object", "Assets/Ground.png", Maths::Vector2f(8550.0f, 675.0f), Maths::Vector2f(400.f, 900.0f), sf::Color::Transparent, true);
        CreateObject("Ground", "Object", "Assets/Ground.png", Maths::Vector2f(9300.0f, 675.0f), Maths::Vector2f(400.f, 900.0f), sf::Color::Transparent, true);
        CreateObject("Ground", "Object", "Assets/Bridge.png", Maths::Vector2f(9700.0f, 675.0f), Maths::Vector2f(700.f, 500.0f), sf::Color::Transparent, false);
        CreateObject("Ground", "Object", "Assets/Bridge.png", Maths::Vector2f(10500.0f, 600.0f), Maths::Vector2f(300.f, 600.0f), sf::Color::Transparent, false);

        //////////////////////////////////
		// Creer un objet de plateforme //
		//////////////////////////////////
        CreateObject("Platform", "Object", "Assets/Platform.png", Maths::Vector2f(1250.f, 700.0f), Maths::Vector2f(300.f, 40.0f), sf::Color::Transparent, true);
        //CreateObject("Platform", "Object", "Assets/Platform.png", Maths::Vector2f(2600.f, 600.0f), Maths::Vector2f(400.f, 40.0f), sf::Color::Transparent, true);
        CreateObject("Platform", "Object", "Assets/Platform.png", Maths::Vector2f(3300.f, 700.0f), Maths::Vector2f(400.f, 40.0f), sf::Color::Transparent, true);
        CreateObject("Platform", "Object", "Assets/Platform.png", Maths::Vector2f(5300.f, 450.0f), Maths::Vector2f(250.f, 40.0f), sf::Color::Transparent, true);
        CreateObject("Platform", "Object", "Assets/Platform.png", Maths::Vector2f(5900.f, 425.0f), Maths::Vector2f(300.f, 40.0f), sf::Color::Transparent, true);
        CreateObject("Platform", "Object", "Assets/Platform.png", Maths::Vector2f(6550.f, 425.0f), Maths::Vector2f(250.f, 40.0f), sf::Color::Transparent, true);
        CreateObject("Platform", "Object", "Assets/Platform.png", Maths::Vector2f(7500.f, 600.0f), Maths::Vector2f(250.f, 40.0f), sf::Color::Transparent, true);

		//////////////////////////////////
		// Creer un objet de decoration //
		//////////////////////////////////

        CreateEnvironment("Cloud", "Environment", "Assets/Cloud.png", Maths::Vector2f(700.0f, 100.0f), Maths::Vector2f(400.0f, 250.0f));
        CreateEnvironment("Bush", "Environment", "Assets/Bush.png", Maths::Vector2f(525.0f, 850.0f), Maths::Vector2f(50.0f, 50.0f));
        CreateEnvironment("Bush", "Environment", "Assets/Bush.png", Maths::Vector2f(575.0f, 850.0f), Maths::Vector2f(50.0f, 50.0f));
        CreateEnvironment("Bush", "Environment", "Assets/Bush.png", Maths::Vector2f(625.0f, 850.0f), Maths::Vector2f(50.0f, 50.0f));
		CreateEnvironment("Tree", "Environment", "Assets/DarkTree.png", Maths::Vector2f(700.0f, 650.0f), Maths::Vector2f(150.0f, 250.0f));
        CreateEnvironment("Bush", "Environment", "Assets/Bush.png", Maths::Vector2f(1000.0f, 850.0f), Maths::Vector2f(50.0f, 50.0f));
        CreateEnvironment("Rock", "Environment", "Assets/Rock3.png", Maths::Vector2f(1400.0f, 850.0f), Maths::Vector2f(75.0f, 50.0f));
        CreateEnvironment("Tree", "Environment", "Assets/DeadTree.png", Maths::Vector2f(1750.0f, 700.0f), Maths::Vector2f(150.0f, 200.0f));
        CreateEnvironment("Cloud", "Environment", "Assets/Cloud.png", Maths::Vector2f(2200.0f, 200.0f), Maths::Vector2f(-300.0f, 150.0f));

        CreateEnvironment("Tombstone", "Environment", "Assets/Tombstone.png", Maths::Vector2f(1400.0f, 650.0f), Maths::Vector2f(50.0f, 50.0f));
        //CreateEnvironment("Tombstone", "Environment", "Assets/Tombstone.png", Maths::Vector2f(2400.0f, 750.0f), Maths::Vector2f(50.0f, 50.0f));
        CreateEnvironment("Tombstone", "Environment", "Assets/Tombstone2.png", Maths::Vector2f(2475.0f, 850.0f), Maths::Vector2f(50.0f, 50.0f));
        CreateEnvironment("Tombstone", "Environment", "Assets/Tombstone4.png", Maths::Vector2f(2555.0f, 825.0f), Maths::Vector2f(40.0f, 75.0f));
        CreateEnvironment("Tombstone", "Environment", "Assets/Tombstone2.png", Maths::Vector2f(2625.0f, 850.0f), Maths::Vector2f(50.0f, 50.0f));
        CreateEnvironment("Tombstone", "Environment", "Assets/Tombstone3.png", Maths::Vector2f(2725.0f, 700.0f), Maths::Vector2f(100.0f, 200.0f));
        CreateEnvironment("Tombstone", "Environment", "Assets/Tombstone.png", Maths::Vector2f(2875.0f, 850.0f), Maths::Vector2f(50.0f, 50.0f));
        CreateEnvironment("Rock", "Environment", "Assets/Rock2.png", Maths::Vector2f(2950.0f, 865.0f), Maths::Vector2f(50.0f, 35.0f));
        //CreateEnvironment("Tombstone", "Environment", "Assets/Tombstone.png", Maths::Vector2f(3025.0f, 750.0f), Maths::Vector2f(50.0f, 50.0f));
        CreateEnvironment("Tombstone", "Environment", "Assets/Tombstone2.png", Maths::Vector2f(3100.0f, 850.0f), Maths::Vector2f(50.0f, 50.0f));
        CreateEnvironment("Rock", "Environment", "Assets/Rock2.png", Maths::Vector2f(3400.0f, 875.0f), Maths::Vector2f(40.0f, 25.0f));
        CreateEnvironment("Bush", "Environment", "Assets/Bush.png", Maths::Vector2f(3500.0f, 850.0f), Maths::Vector2f(75.0f, 50.0f));
        CreateEnvironment("Tombstone", "Environment", "Assets/Tombstone2.png", Maths::Vector2f(3450.0f, 650.0f), Maths::Vector2f(50.0f, 50.0f));
        CreateEnvironment("Tree", "Environment", "Assets/DeadTree2.png", Maths::Vector2f(3750.0f, 700.0f), Maths::Vector2f(150.0f, 200.0f));
        CreateEnvironment("Tree", "Environment", "Assets/DeadTree4.png", Maths::Vector2f(4500.0f, 675.0f), Maths::Vector2f(-150.0f, 130.0f));
        CreateEnvironment("Tree", "Environment", "Assets/DeadTree4.png", Maths::Vector2f(4550.0f, 875.0f), Maths::Vector2f(150.0f, 130.0f));

        CreateEnvironment("Tree", "Environment", "Assets/DarkTree3.png", Maths::Vector2f(4075.0f, 400.0f), Maths::Vector2f(150.0f, 200.0f));
        CreateEnvironment("Cloud", "Environment", "Assets/Cloud.png", Maths::Vector2f(4650.0f, 150.0f), Maths::Vector2f(-300.0f, 150.0f));

        CreateEnvironment("Tombstone", "Environment", "Assets/Tombstone2.png", Maths::Vector2f(5500.0f, 750.0f), Maths::Vector2f(50.0f, 50.0f));
        CreateEnvironment("Tombstone", "Environment", "Assets/Tombstone6.png", Maths::Vector2f(5650.0f, 600.0f), Maths::Vector2f(100.0f, 200.0f));
        CreateEnvironment("Tombstone", "Environment", "Assets/Tombstone2.png", Maths::Vector2f(5800.0f, 750.0f), Maths::Vector2f(50.0f, 50.0f));
        CreateEnvironment("Tombstone", "Environment", "Assets/Tombstone2.png", Maths::Vector2f(5900.0f, 750.0f), Maths::Vector2f(50.0f, 50.0f));
        CreateEnvironment("Tombstone", "Environment", "Assets/Door.png", Maths::Vector2f(10600.0f, 475.0f), Maths::Vector2f(150.0f, 150.0f));
        
        /////////////////////////////////
        //    Creer l'entite joueur    //
        /////////////////////////////////

        Maths::Vector2f playerSize = Maths::Vector2f(75.0f, 75.0f);

        GameObject* player = CreateInGameObject("Player", "Player", Maths::Vector2f(2000.0f / 2 - playerSize.x / 2, 0.0f), playerSize, 1.0f, sf::Color::Transparent);
        player->CreateComponent<Player>();

        //////////////////////////////////
        //  Creer des entites ennemies  //
        //////////////////////////////////

        Maths::Vector2f wandererSize = Maths::Vector2f(50.0f, 50.0f);
		Maths::Vector2f throwerSize = Maths::Vector2f(65.0f, 65.0f);

        GameObject* enemy = CreateInGameObject("Wanderer", "Enemy", Maths::Vector2f(2000.0f, 0.0f), wandererSize, 1.0f, sf::Color::Transparent);
        enemy->CreateComponent<Enemy>();

        GameObject* enemy2 = CreateInGameObject("Wizard", "Enemy", Maths::Vector2f(1500.0f, 0.0f), throwerSize, 1.0f, sf::Color::Transparent);
        enemy2->CreateComponent<Enemy>();

        GameObject* enemy3 = CreateInGameObject("Wizard", "Enemy", Maths::Vector2f(3200.0f, 0.0f), throwerSize, 1.0f, sf::Color::Transparent);
        enemy3->CreateComponent<Enemy>();

        GameObject* enemy4 = CreateInGameObject("Wanderer", "Enemy", Maths::Vector2f(3500.0f, 0.0f), wandererSize, 1.0f, sf::Color::Transparent);
        enemy4->CreateComponent<Enemy>();

        GameObject* enemy5 = CreateInGameObject("Wanderer", "Enemy", Maths::Vector2f(5800.0f, 0.0f), wandererSize, 1.0f, sf::Color::Transparent);
        enemy5->CreateComponent<Enemy>();

        GameObject* enemy6 = CreateInGameObject("Wanderer", "Enemy", Maths::Vector2f(6100.0f, 0.0f), wandererSize, 1.0f, sf::Color::Transparent);
        enemy6->CreateComponent<Enemy>();

        GameObject* enemy7 = CreateInGameObject("Wanderer", "Enemy", Maths::Vector2f(7100.0f, 0.0f), wandererSize, 1.0f, sf::Color::Transparent);
        enemy7->CreateComponent<Enemy>();

        GameObject* enemy8 = CreateInGameObject("Wanderer", "Enemy", Maths::Vector2f(8200.0f, 0.0f), throwerSize, 1.0f, sf::Color::Transparent);
        enemy8->CreateComponent<Enemy>();

        // cree le boss.
		GameObject* boss = CreateInGameObject("Boss", "Enemy", Maths::Vector2f(10000.0f, 0.0f), Maths::Vector2f(200.0f, 200.0f), 1.0f, sf::Color::Transparent);
		boss->CreateComponent<Enemy>();
        

    }
};
