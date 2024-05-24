// MainMenuScene.h
#pragma once
#include "Scene.h"

class MainMenuScene : public Scene
{
public:
    MainMenuScene() : Scene("MainMenuScene")
    {
        // Créez ici les éléments de votre menu principal.
        // Par exemple, vous pouvez créer des GameObjects pour les boutons "Jouer", "Options", "Quitter", etc.
        // Vous pouvez également ajouter des écouteurs d'événements à ces boutons pour changer de scène lorsque l'utilisateur clique sur eux.
    }
};

