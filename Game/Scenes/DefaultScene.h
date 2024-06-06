#pragma once

#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Scene.h"
#include "DefeatScene.h"
#include "Background.h"
#include <SFML/Audio.hpp>


// La classe DefaultScene herite de la classe Scene
// et represente la scene par defaut de votre jeu.
class DefaultScene final : public Scene
{
public:
    // Constructeur de la classe DefaultScene.
    // Cree les objets de la scene.
    DefaultScene() : Scene("DefaultScene")
    {

		// Créez un objet sf::Music 1 et 2 pour jouer de la musique de fond.
        //sf::Music backgroundMusic1;
        //sf::Music backgroundMusic2;
        
        // Chargez la musique à partir d'un fichier
        //if (!backgroundMusic.openFromFile("Assets/backgroundmusic.ogg")) {
            // Gérez l'erreur si le fichier ne peut pas être chargé
        //}

        // Jouez la musique
        //backgroundMusic.play();
         
        //if (!backgroundMusic2.openFromFile("Assets/wind.ogg")) {
            // Gérez l'erreur si le fichier ne peut pas être chargé
        //}
         
        // Réduisez le volume du son du vent à 50% du maximum
        //backgroundMusic2.setVolume(50);
        
        // Jouez la deuxième musique
        //backgroundMusic2.play();

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
        CreateObject("Ground", "Object", "Assets/Ground.png", Maths::Vector2f(9700.0f, 675.0f), Maths::Vector2f(700.f, 500.0f), sf::Color::Transparent, true);
        CreateObject("Ground", "Object", "Assets/Ground.png", Maths::Vector2f(10700.0f, 600.0f), Maths::Vector2f(500.f, 600.0f), sf::Color::Transparent, true);
        CreateObject("Ground", "Object", "Assets/Ground.png", Maths::Vector2f(11200.0f, -1000.0f), Maths::Vector2f(1000.f, 3000.0f), sf::Color::Transparent, true);

        //////////////////////////////////
		// Creer un objet de plateforme //
		//////////////////////////////////
        CreateObject("Platform", "Object", "Assets/Platform.png", Maths::Vector2f(1250.f, 700.0f), Maths::Vector2f(300.f, 40.0f), sf::Color::Transparent, true);
        //CreateObject("Platform", "Object", "Assets/Platform.png", Maths::Vector2f(2600.f, 600.0f), Maths::Vector2f(400.f, 40.0f), sf::Color::Transparent, true);
        CreateObject("Platform", "Object", "Assets/Platform.png", Maths::Vector2f(3300.f, 700.0f), Maths::Vector2f(400.f, 40.0f), sf::Color::Transparent, true);
        CreateObject("Platform", "Object", "Assets/Platform.png", Maths::Vector2f(5300.f, 450.0f), Maths::Vector2f(250.f, 40.0f), sf::Color::Transparent, true);
        CreateObject("Platform", "Object", "Assets/Platform.png", Maths::Vector2f(5900.f, 425.0f), Maths::Vector2f(300.f, 40.0f), sf::Color::Transparent, true);
        CreateObject("Platform", "Object", "Assets/Platform.png", Maths::Vector2f(6550.f, 425.0f), Maths::Vector2f(250.f, 40.0f), sf::Color::Transparent, true);
        CreateObject("Platform", "Object", "Assets/Platform.png", Maths::Vector2f(7550.f, 900.0f), Maths::Vector2f(80.f, 40.0f), sf::Color::Transparent, true);

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

        CreateEnvironment("Tree", "Environment", "Assets/DeadTree2.png", Maths::Vector2f(6800.0f, 555.0f), Maths::Vector2f(150.0f, 250.0f));
        CreateEnvironment("Tombstone", "Environment", "Assets/Tombstone3.png", Maths::Vector2f(7000.0f, 700.0f), Maths::Vector2f(50.0f, 100.0f));
        CreateEnvironment("Bush", "Environment", "Assets/Bush.png", Maths::Vector2f(7150.0f, 750.0f), Maths::Vector2f(75.0f, 50.0f));

        CreateEnvironment("Tree", "Environment", "Assets/DarkTree.png", Maths::Vector2f(8050.0f, 555.0f), Maths::Vector2f(150.0f, 250.0f));
        CreateEnvironment("Bush", "Environment", "Assets/Bush.png", Maths::Vector2f(8250.0f, 750.0f), Maths::Vector2f(75.0f, 50.0f));
        CreateEnvironment("Bush", "Environment", "Assets/Bush.png", Maths::Vector2f(8350.0f, 750.0f), Maths::Vector2f(75.0f, 50.0f));
        CreateEnvironment("Bush", "Environment", "Assets/Bush.png", Maths::Vector2f(8450.0f, 750.0f), Maths::Vector2f(75.0f, 50.0f));

        CreateEnvironment("Tree", "Environment", "Assets/DarkTree2.png", Maths::Vector2f(9350.0f, 425.0f), Maths::Vector2f(150.0f, 250.0f));
        CreateEnvironment("Tombstone", "Environment", "Assets/Tombstone2.png", Maths::Vector2f(9550.0f, 625.0f), Maths::Vector2f(50.0f, 50.0f));
        CreateEnvironment("Tombstone", "Environment", "Assets/Tombstone2.png", Maths::Vector2f(9650.0f, 625.0f), Maths::Vector2f(50.0f, 50.0f));
        CreateEnvironment("Bush", "Environment", "Assets/Bush.png", Maths::Vector2f(9750.0f, 625.0f), Maths::Vector2f(50.0f, 50.0f));
        CreateEnvironment("Tombstone", "Environment", "Assets/Tombstone.png", Maths::Vector2f(9850.0f, 625.0f), Maths::Vector2f(50.0f, 50.0f));
        CreateEnvironment("Rock", "Environment", "Assets/Rock.png", Maths::Vector2f(9950.0f, 625.0f), Maths::Vector2f(50.0f, 50.0f));
        CreateEnvironment("Bush", "Environment", "Assets/Bush.png", Maths::Vector2f(10050.0f, 625.0f), Maths::Vector2f(50.0f, 50.0f));

		CreateEnvironment("Tree", "Environment", "Assets/DeadTree2.png", Maths::Vector2f(10150.0f, 425.0f), Maths::Vector2f(150.0f, 250.0f));

        CreateEnvironment("Tombstone", "Environment", "Assets/Door.png", Maths::Vector2f(11000.0f, 470.0f), Maths::Vector2f(150.0f, 150.0f));
        
        //////////////////////////////////
        //         Creer de L'UI        //
        //////////////////////////////////

        CreateEnvironment("Touches", "Touches", "Assets/Touches.png", Maths::Vector2f(550.0f, 350.0f), Maths::Vector2f(654.0f, 336.0f));

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
        Maths::Vector2f MidSize = Maths::Vector2f(120.0f, 120.0f);
        Maths::Vector2f BossSize = Maths::Vector2f(150.0f, 150.0f);

        GameObject* enemy = CreateInGameObject("Wanderer", "Enemy", Maths::Vector2f(2000.0f, 0.0f), wandererSize, 1.0f, sf::Color::Transparent);
        enemy->CreateComponent<Enemy>();

		GameObject* enemy2 = CreateInGameObject("Wanderer", "Enemy", Maths::Vector2f(1500.0f, 0.0f), wandererSize, 1.0f, sf::Color::Transparent);
        enemy2->CreateComponent<Enemy>();

        GameObject* enemy3 = CreateInGameObject("Wizard", "Enemy", Maths::Vector2f(3200.0f, 0.0f), throwerSize, 1.0f, sf::Color::Transparent);
        enemy3->CreateComponent<Enemy>();

        GameObject* enemy4 = CreateInGameObject("Wanderer", "Enemy", Maths::Vector2f(3500.0f, 0.0f), wandererSize, 1.0f, sf::Color::Transparent);
        enemy4->CreateComponent<Enemy>();

        GameObject* enemy5 = CreateInGameObject("Wizard", "Enemy", Maths::Vector2f(5800.0f, 0.0f), MidSize, 1.0f, sf::Color::Transparent);
        enemy5->CreateComponent<Enemy>();

        GameObject* enemy6 = CreateInGameObject("Wanderer", "Enemy", Maths::Vector2f(6100.0f, 0.0f), wandererSize, 1.0f, sf::Color::Transparent);
        enemy6->CreateComponent<Enemy>();

        GameObject* enemy7 = CreateInGameObject("Wizard", "Enemy", Maths::Vector2f(6550.0f, 425.0f - 65.0f), throwerSize, 1.0f, sf::Color::Transparent);
        enemy7->CreateComponent<Enemy>();

        GameObject* enemy8 = CreateInGameObject("Wizard", "Enemy", Maths::Vector2f(7100.0f, 0.0f), throwerSize, 1.0f, sf::Color::Transparent);
        enemy8->CreateComponent<Enemy>();

        GameObject* enemy9 = CreateInGameObject("Wizard", "Enemy", Maths::Vector2f(8200.0f, 0.0f), throwerSize, 1.0f, sf::Color::Transparent);
        enemy9->CreateComponent<Enemy>();

        GameObject* enemy10 = CreateInGameObject("Wizard", "Enemy", Maths::Vector2f(10000.0f, 0.0f), BossSize, 1.0f, sf::Color::Transparent);
        enemy10->CreateComponent<Enemy>();

        GameObject* enemy11 = CreateInGameObject("Wizard", "Enemy", Maths::Vector2f(10500.0f, 0.0f), BossSize, 1.0f, sf::Color::Transparent);
        enemy11->CreateComponent<Enemy>();


    }
};
