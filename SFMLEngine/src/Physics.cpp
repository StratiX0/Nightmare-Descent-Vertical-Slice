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
    GameObject* ground = GetOwner()->GetScene()->FindGameObject("Ground");
    SquareCollider* groundCollider = ground->GetComponent<SquareCollider>();
    if (collider && ground)
    {
		if (SquareCollider::IsColliding(*collider, *groundCollider))
		{
			SetJumping(false);
			return true;
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
        // La gravité est maintenant divisée par la masse
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