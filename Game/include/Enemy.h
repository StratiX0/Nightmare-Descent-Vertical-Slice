#pragma once
#include "Component.h"
#include "Scene.h" 

class Physics;
class AnimatedSpriteComponent;

// La classe Enemy herite de la classe Component et represente un ennemi dans le jeu.
class Enemy : public Component
{
public:

	void Start() override
	{
		name = GetOwner()->GetName();
	}

    // Met a jour l'ennemi.
    void Update(const float _delta_time) override
    {

        // Recupere le GameObject proprietaire de ce composant.
        GameObject* owner = GetOwner();

        SetPlatformLimits();

        // Recupere la position actuelle du GameObject.
        Maths::Vector2<float> position = owner->GetPosition();

        // Si l'ennemi atteint le bord droit de sa plateforme, il se deplace vers la gauche.
        if (position.x + owner->GetComponent<RectangleShapeRenderer>()->GetSize().x >= rightLimit || owner->GetComponent<Physics>()->collidingRight)
        {
            direction = -1;
            owner->GetComponent<AnimatedSpriteComponent>()->SetDirection(AnimatedSpriteComponent::MovementDirection::Left);
            owner->GetComponent<AnimatedSpriteComponent>()->SetState(AnimatedSpriteComponent::PlayerSpriteState::Running);
        }

        // Si l'ennemi atteint le bord gauche de sa plateforme, il se deplace vers la droite.
        else if (position.x <= leftLimit || owner->GetComponent<Physics>()->collidingLeft)
        {
            direction = 1;
            owner->GetComponent<AnimatedSpriteComponent>()->SetDirection(AnimatedSpriteComponent::MovementDirection::Right);
            owner->GetComponent<AnimatedSpriteComponent>()->SetState(AnimatedSpriteComponent::PlayerSpriteState::Running);
        }

        // Si l'ennemie est mort, change la couleur du RectangleShapeRenderer en rouge.
        if (owner->GetComponent<Health>()->IsDead())
        {
            owner->GetComponent<RectangleShapeRenderer>()->SetColor(sf::Color::Red);
        }

        // Met a jour la position de l'ennemi.
        position.x += direction * speed * _delta_time;
        owner->SetPosition(position);
    }

    // Methodes pour definir et obtenir les limites de la plateforme de l'ennemi.
    void SetPlatformLimits()
    {
		SquareCollider* collider = GetOwner()->GetComponent<SquareCollider>();
        for (auto& game_object : GetOwner()->GetScene()->GetGameObjects())
        {
            if (game_object->GetType() == "Object")
            {
                SquareCollider* objectCollider = game_object->GetComponent<SquareCollider>();
                if (SquareCollider::IsColliding(*collider, *objectCollider))
                {
                    SquareCollider* platformCollider = game_object->GetComponent<SquareCollider>();
                    Maths::Vector2f platformPosition = game_object->GetPosition();
                    leftLimit = platformPosition.x;
                    rightLimit = platformPosition.x + platformCollider->GetWidth();
                }
            }
        }
    }

private:

    std::string name;

    // Variables de deplacement de l'ennemi.
    float speed = 100.0f;
    int direction = 1; // 1 pour la droite, -1 pour la gauche.

    // Variables qui stockent les limites de la plateforme de l'ennemi.
    float leftLimit = 0.0f;
    float rightLimit = 0.0f;
};
