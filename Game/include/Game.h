#pragma once
#include "Component.h"
#include "Engine.h"
#include "Modules/SceneModule.h"
#include "../Scenes/DefaultScene.h"
#include "Scene.h"

class Game : public Component
{
    void Update(float delta_time) override {

        GameObject* player = GetOwner();

        // Si le joueur est au-dessus de l'ennemi, inflige des degâts à l'ennemi et met le temps d'invincibilite.
        if (player->GetComponent<Health>()->IsDead())
        {
            printf("mort");
            /*GameObject* Defeat = CreateEnvironment("Play", "Button", "Assets/Play1.png", Maths::Vector2f(760.0f, 470.0f), Maths::Vector2f(447.0f, 200.0f));*/
        }
    }


};