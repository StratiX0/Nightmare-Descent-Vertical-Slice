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
    void Update(const float delta_time) override {

        GameObject* Door = GetOwner();
        Engine* engine = Engine::GetInstance();
        SceneModule* scene_module = engine->GetModuleManager()->GetModule<SceneModule>();

        if (Door->GetComponent<Physics>()->DoorIsColliding() == true) {
            Door->GetComponent<AnimatedSpriteComponent>()->SetState(AnimatedSpriteComponent::SpriteState::Running);
        }
        else if (Door->GetComponent<Physics>()->DoorIsColliding() == false) {
            Door->GetComponent<AnimatedSpriteComponent>()->SetState(AnimatedSpriteComponent::SpriteState::Idle);
        }
        if (InputModule::GetKey(sf::Keyboard::E) && Door->GetComponent<Physics>()->DoorIsReached() == true) {
            scene_module->SetScene<VictoryScene>();
        }
            
    }
};
