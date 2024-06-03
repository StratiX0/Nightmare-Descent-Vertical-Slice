#pragma once
#include "Component.h"
#include "Engine.h"
#include "Modules/SceneModule.h"
#include "../Scenes/DefaultScene.h"
#include "../Scenes/MenuScene.h"
#include "TimeModule.h"

class Menu : public Component
{
    void Update(const float delta_time) override {

        Engine* engine = Engine::GetInstance();
        SceneModule* scene_module = engine->GetModuleManager()->GetModule<SceneModule>();
        sf::Vector2i mouse = sf::Mouse::getPosition();

        if (mouse.x >= 818 && mouse.x <= 1124) {
            if (mouse.y >= 514 && mouse.y <= 620) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    scene_module->SetScene<DefaultScene>();
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