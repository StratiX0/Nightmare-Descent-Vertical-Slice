// Physics.cpp
#include "Physics.h"

Physics::Physics()
{
	isJumping = false;
}

Physics::~Physics()
{
}

bool Physics::IsGrounded()
{
    // Vérifie si le gameObject est en contact avec le sol
    SquareCollider* collider = GetOwner()->GetComponent<SquareCollider>();
	for (auto& gameObject : GetOwner()->GetScene()->GetGameObjects())
    {
        if (gameObject->GetType() == "Object")
        {
			SquareCollider* groundCollider = gameObject->GetComponent<SquareCollider>();
            if (collider && groundCollider)
            {
                if (SquareCollider::IsColliding(*collider, *groundCollider) && GetOwner()->GetPosition().y < gameObject->GetPosition().y)
                {
					SetJumping(false);
					return true;
				}
			}
		}
	}
    return false;
}

void Physics::Update(float _delta_time)
{
    Maths::Vector2f position = GetOwner()->GetPosition();
    Maths::Vector2f velocity = GetOwner()->GetVelocity();

    if (!IsGrounded())
    {
        velocity += (gravity / mass) * _delta_time;
    }
    else
    {
        velocity = Maths::Vector2f(0.0f, 0.0f);
    }

    position += velocity * _delta_time;

    GetOwner()->SetPosition(position);
    GetOwner()->SetVelocity(velocity);
}