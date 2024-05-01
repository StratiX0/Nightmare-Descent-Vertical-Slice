#pragma once
#include "Component.h"
#include "InputModule.h"

class Physics;
class AnimatedSpriteComponent;

class Player : public Component
{
public:

	float lerp(float a, float b, float t) 
	{
		return a + t * (b - a);
	}

    void Update(const float _delta_time) override
    {
        Maths::Vector2<float> position = GetOwner()->GetPosition();
        Maths::Vector2<float> velocity;
        GameObject* owner = GetOwner();

        if (InputModule::GetKey(sf::Keyboard::D))
        {
            velocity.x += speed * _delta_time;
			owner->GetComponent<AnimatedSpriteComponent>()->SetDirection(AnimatedSpriteComponent::MovementDirection::Right);
        }
        if (InputModule::GetKey(sf::Keyboard::Q))
        {
            velocity.x -= speed * _delta_time;
			owner->GetComponent<AnimatedSpriteComponent>()->SetDirection(AnimatedSpriteComponent::MovementDirection::Left);
        }

        if (InputModule::GetKey(sf::Keyboard::Z) && !owner->GetComponent<Physics>()->IsJumping())
        {
            targetY = owner->GetPosition().y - jumpForce;
            owner->GetComponent<Physics>()->SetJumping(true);
            owner->GetComponent<AnimatedSpriteComponent>()->SetDirection(AnimatedSpriteComponent::MovementDirection::Up);
        }
        if (InputModule::GetKey(sf::Keyboard::S))
        {
            //velocity.y += speed * _delta_time;
        }

        if (owner->GetComponent<Physics>()->IsJumping())
        {
            position.y = lerp(owner->GetPosition().y, targetY, _delta_time);
            if (position.y <= targetY)
            {
                position.y = targetY;
                owner->GetComponent<Physics>()->SetJumping(false);
            }
        }

        position.x += velocity.x;
        GetOwner()->SetPosition(position);
    }


private:

	float targetY = 0.0f;
	float newY = 0.0f;
	float jumpForce = 1000.0f;
	float speed = 400.0f;
};

