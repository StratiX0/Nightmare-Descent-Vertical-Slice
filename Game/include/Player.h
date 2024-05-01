#pragma once
#include "Component.h"
#include "InputModule.h"

class Physics;
class AnimatedSpriteComponent;
class Background;
class SquareCollider;

class Player : public Component
{
public:

    void Update(const float _delta_time) override
    {
        GameObject* owner = GetOwner();
        Maths::Vector2<float> position = owner->GetPosition();
        Maths::Vector2<float> velocity = owner->GetVelocity();
        gravity = owner->GetComponent<Physics>()->gravity;

        GetOwner()->SetPosition(Maths::Vector2f(position.x, position.y - 0.1f));

        if (InputModule::GetKey(sf::Keyboard::D))
        {
			if (!owner->GetComponent<Physics>()->collidingRight)
            {
                owner->GetComponent<AnimatedSpriteComponent>()->SetDirection(AnimatedSpriteComponent::MovementDirection::Right);
                for (auto& background : owner->GetScene()->GetBackgrounds())
                {
                    background->SetPosition(background->GetPosition().x - speed * _delta_time, background->GetPosition().y);
                    if (background->GetPosition().x <= 0.0f - 1600.0f)
                    {
                        background->SetPosition(1600.0f, background->GetPosition().y);
                    }
                }
				for (auto& game_object : owner->GetScene()->GetGameObjects())
                {
					game_object->SetPosition(Maths::Vector2f(game_object->GetPosition().x - speed * _delta_time, game_object->GetPosition().y));
				}
			}
        }
        if (InputModule::GetKey(sf::Keyboard::Q))
        {
            if (!owner->GetComponent<Physics>()->collidingLeft)
            {
                owner->GetComponent<AnimatedSpriteComponent>()->SetDirection(AnimatedSpriteComponent::MovementDirection::Left);
                for (auto& background : owner->GetScene()->GetBackgrounds())
                {
                    background->SetPosition(background->GetPosition().x + speed * _delta_time, background->GetPosition().y);
                    background->GetSize().x;
                    if (background->GetPosition().x >= 1600.0f)
                    {
                        background->SetPosition(-1600.0f, background->GetPosition().y);
                    }
                }
                for (auto& game_object : owner->GetScene()->GetGameObjects())
                {
                    game_object->SetPosition(Maths::Vector2f(game_object->GetPosition().x + speed * _delta_time, game_object->GetPosition().y));
                }
            }

        }

        if (InputModule::GetKey(sf::Keyboard::S))
        {
            //velocity.y += speed * _delta_time;
        }

        if (InputModule::GetKey(sf::Keyboard::Z) && !owner->GetComponent<Physics>()->IsJumping())
        {
            velocity.y = -jumpForce; // Ajoute une force vers le haut
            owner->GetComponent<Physics>()->SetJumping(true);
            owner->GetComponent<AnimatedSpriteComponent>()->SetDirection(AnimatedSpriteComponent::MovementDirection::Up);
        }

        if (owner->GetComponent<Physics>()->IsJumping())
        {
            velocity.y += gravity.y * _delta_time; // Applique la gravité
            if (owner->GetComponent<Physics>()->IsCollidingAbove())
            {
                velocity.y = 0.0f; // Arrête le mouvement vertical si une collision est détectée au-dessus du joueur
            }
        }

        position += velocity * _delta_time;

        owner->SetVelocity(velocity);
        owner->SetPosition(position);
    }


private:

	float targetY = 0.0f;
	float newY = 0.0f;
	float jumpForce = 800.0f;
	float speed = 600.0f;
	Maths::Vector2<float> gravity;
};

