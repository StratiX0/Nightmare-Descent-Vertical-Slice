#pragma once
#pragma once

#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Background.h"
#include "Menu.h"


// La classe DefaultScene herite de la classe Scene
// et represente la scene par defaut de votre jeu.

class MenuScene : public Scene
{
public:
    MenuScene() : Scene("MenuScene")
    {
        // Créez ici les éléments de votre menu principal.
        // Par exemple, vous pouvez créer des boutons "Jouer", "Options" et "Quitter".

        // Cree les arriere-plans de la scene.
        CreateBackgrounds("Assets/Background.png");

        //Placer le logo
        CreateEnvironment("Logo", "Logo", "Assets/Logo2.png", Maths::Vector2f(600.0f, 10.0f), Maths::Vector2f(749.0f, 500.0f));

        // Créer le bouton "Jouer"
        GameObject* playButton = CreateEnvironment("Play", "Button", "Assets/Play1.png", Maths::Vector2f(760.0f, 470.0f), Maths::Vector2f(447.0f, 200.0f));


        // Créer le bouton "Options" // (818;918) ; 1124,816
        GameObject* optionsButton = CreateEnvironment("Options", "Button", "Assets/Options1.png", Maths::Vector2f(760.0f, 670.0f), Maths::Vector2f(447.0f, 200.0f));
        // Lorsque l'utilisateur clique sur "Options", ouvrez le menu des options.
        // Vous devrez implémenter cette fonctionnalité.

        // Créer le bouton "Quitter" //(818;922) ; 1124,1016
        GameObject* quitButton = CreateEnvironment("Quit", "Button", "Assets/Quit1.png", Maths::Vector2f(760.0f, 870.0f), Maths::Vector2f(447.0f, 200.0f));

        CreateGameObject("Menu", "Menu", 1)->CreateComponent<Menu>();
    }
};