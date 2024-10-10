#pragma once
#include "Component.h"
#include "Engine.h"
#include "Modules/SceneModule.h"
#include "../Scenes/DefaultScene.h"
#include "../Scenes/VictoryScene.h"
#include "DoorClass.h"
#include "TimeModule.h"


class DoorGame : public Component
{
public:

    /*Créez un objet sf::Music 1 et 2 pour jouer de la musique de fond.*/
    sf::Music backgroundMusic;
    sf::Music backgroundMusic2;

    DoorGame() {
        /*Chargez la musique à partir d'un fichier*/
        if (!backgroundMusic.openFromFile("Assets/summon_of_the_fallen.wav")) {
            printf("impossible de charger le son");
            //Gérez l'erreur si le fichier ne peut pas être chargé
        }

        if (!backgroundMusic2.openFromFile("Assets/wind.ogg")) {
            //Gérez l'erreur si le fichier ne peut pas être chargé
        }

        //Réduisez le volume du son du vent à 50% du maximum
        backgroundMusic.setVolume(30);
        //Réduisez le volume du son du vent à 50% du maximum
        backgroundMusic2.setVolume(20);

        /*Jouez la musique*/
        backgroundMusic.play();
        //Jouez la deuxième musique
        backgroundMusic2.play();

        /*Jouez la musique*/
        backgroundMusic.setLoop(true);
        //Jouez la deuxième musique
        backgroundMusic2.setLoop(true);
    }

    void Update(const float delta_time) override {

        GameObject* Door = GetOwner();
        Engine* engine = Engine::GetInstance();
        SceneModule* scene_module = engine->GetModuleManager()->GetModule<SceneModule>();
        // Recupere le GameObject de type "Player".
        GameObject* player = GetOwner()->GetScene()->FindGameObjectType("Player");

        if (Door->GetComponent<Physics>()->DoorIsColliding() == true && Door->GetComponent<Physics>()->DoorIsOpen() == false) {
            Door->GetComponent<AnimatedSpriteComponent>()->SetState(AnimatedSpriteComponent::SpriteState::Running);
            if (Door->GetComponent<AnimatedSpriteComponent>()->GetCurrentFrame() >= 3) {
                Door->GetComponent<Physics>()->SetDoorIsOpen(true);
            }
        }
        else if (Door->GetComponent<Physics>()->DoorIsColliding() == false && Door->GetComponent<Physics>()->DoorIsOpen() == false) {
            Door->GetComponent<AnimatedSpriteComponent>()->SetState(AnimatedSpriteComponent::SpriteState::Idle);
        }
        else if (Door->GetComponent<Physics>()->DoorIsOpen() == true) {
            Door->GetComponent<AnimatedSpriteComponent>()->SetState(AnimatedSpriteComponent::SpriteState::Jump);
        }
        if (InputModule::GetKey(sf::Keyboard::E) && Door->GetComponent<Physics>()->DoorIsReached() == true) {
            /*Jouez la musique*/
            backgroundMusic.stop();
            //Jouez la deuxième musique
            backgroundMusic2.stop();

            scene_module->SetScene<VictoryScene>();
        }
        if (player->GetComponent<Health>()->IsDead())
        {
            /*Jouez la musique*/
            backgroundMusic.stop();
            //Jouez la deuxième musique
            backgroundMusic2.stop();
        }
            
    }
};
