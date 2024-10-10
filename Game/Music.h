#pragma once
#include "Component.h"
#include "Engine.h"
#include "Modules/SceneModule.h"
#include "../Scenes/DefeatScene.h"
#include "../Scenes/VictoryScene.h"
#include "../Scenes/MenuScene.h"
#include "TimeModule.h"
#include <SFML/Audio.hpp>

class Music : public Component
{
public:


    Engine* engine = Engine::GetInstance();
    SceneModule* scene_module = engine->GetModuleManager()->GetModule<SceneModule>();
    sf::Vector2i mouse = sf::Mouse::getPosition();

    sf::SoundBuffer defeatbuffer;
    sf::Sound defeatsound;
    sf::SoundBuffer victorybuffer;
    sf::Sound victorysound;

    Music() {
        // Chargez le son à partir d'un fichier
        if (!defeatbuffer.loadFromFile("Assets/Defeat_Sound.ogg")) {
            // Gérez l'erreur si le fichier ne peut pas être chargé
        }

        // Chargez le son à partir d'un fichier
        if (!victorybuffer.loadFromFile("Assets/Win_Sound.ogg")) {
            // Gérez l'erreur si le fichier ne peut pas être chargé
        }

        // Créez un objet sf::Sound pour jouer le son
        defeatsound.setBuffer(defeatbuffer);
        victorysound.setBuffer(victorybuffer);

        if (scene_module->GetScene("DefeatScene")) {
            // Jouez le son
            defeatsound.play();
        }
        else if (scene_module->GetScene("VictoryScene")) {
            // Jouez le son
            victorysound.play();
        }

    }

    void Update(const float delta_time) override {

        if (delta_time >= 8) {
            scene_module->SetScene<MenuScene>();
        }

    }
};
