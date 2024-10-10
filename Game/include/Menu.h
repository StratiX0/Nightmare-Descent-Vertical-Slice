#pragma once
#include "Component.h"
#include "Engine.h"
#include "Modules/SceneModule.h"
#include "TimeModule.h"
#include <SFML/Audio.hpp>

class Menu : public Component
{
public:

    Engine* engine = Engine::GetInstance();
    SceneModule* scene_module = engine->GetModuleManager()->GetModule<SceneModule>();
    sf::Vector2i mouse = sf::Mouse::getPosition();

    //Menu() {
    //    /*Créez un objet sf::Music 1 et 2 pour jouer de la musique de fond.*/
    //    sf::Music backgroundMusicMenu;

    //    /*Chargez la musique à partir d'un fichier*/
    //    if (!backgroundMusicMenu.openFromFile("Assets/summon_of_the_fallen.wav")) {
    //        printf("impossible de charger le son");
    //        //Gérez l'erreur si le fichier ne peut pas être chargé
    //    }

    //    /*Jouez la musique*/
    //    backgroundMusicMenu.setVolume(130);
    //    backgroundMusicMenu.play();
    //    backgroundMusicMenu.setLoop(true);
    //}

    void Update(const float delta_time) override {

        if (mouse.x >= 818 && mouse.x <= 1124) {
            if (mouse.y >= 514 && mouse.y <= 620) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    engine->GetModuleManager()->GetModule<SceneModule>()->SetScene<DefaultScene>();
                }
            }
        }

        if (mouse.x >= 818 && mouse.x <= 1124) {
            if (mouse.y >= 922 && mouse.y <= 1016) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    engine->Quit();
                }
            }
        }
    }
};