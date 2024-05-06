#include "Physics.h"

Physics::Physics()
{
	isJumping = false;
    collidingLeft = false;
    collidingRight = false;
}

Physics::~Physics()
{
}

bool Physics::IsGrounded()
{
    Maths::Vector2f velocity = GetOwner()->GetVelocity();
    SquareCollider* collider = GetOwner()->GetComponent<SquareCollider>();
    Maths::Vector2f position = GetOwner()->GetPosition();
    for (auto& gameObject : GetOwner()->GetScene()->GetGameObjects())
    {
        if (gameObject->GetType() == "Object")
        {
            SquareCollider* groundCollider = gameObject->GetComponent<SquareCollider>();
            if (collider && groundCollider)
            {
                bool aboveGround = GetOwner()->GetPosition().y + collider->GetHeight() - 0.5f < gameObject->GetPosition().y;
                // Vérifie si le joueur est sur la même tranche de position x que l'objet
                bool sameXRange = (position.x + collider->GetWidth() > gameObject->GetPosition().x) && (position.x < gameObject->GetPosition().x + groundCollider->GetWidth());
                if (SquareCollider::IsColliding(*collider, *groundCollider) && aboveGround && sameXRange)
                {
                    GetOwner()->SetPosition(Maths::Vector2f(position.x, gameObject->GetPosition().y - collider->GetHeight()));
                    SetJumping(false);
                    return true;
                }
            }
        }
    }
    return false;
}


bool Physics::IsCollidingAbove()
{
    Maths::Vector2f velocity = GetOwner()->GetVelocity();
    SquareCollider* collider = GetOwner()->GetComponent<SquareCollider>();
    Maths::Vector2f position = GetOwner()->GetPosition();
    for (auto& gameObject : GetOwner()->GetScene()->GetGameObjects())
    {
        if (gameObject->GetType() == "Object")
        {
            SquareCollider* objectCollider = gameObject->GetComponent<SquareCollider>();
            if (collider && objectCollider)
            {
                bool underObject = position.y > (gameObject->GetPosition().y + objectCollider->GetHeight() - 1);
                if (SquareCollider::IsColliding(*collider, *objectCollider) && underObject)
                {
                    GetOwner()->SetPosition(Maths::Vector2f(position.x, gameObject->GetPosition().y + objectCollider->GetHeight() + 1.0f));
                    return true;
                }
            }
        }
    }
    return false;
}

void Physics::IsLateralColliding()
{
    SquareCollider* collider = GetOwner()->GetComponent<SquareCollider>();
    Maths::Vector2f position = GetOwner()->GetPosition();
    for (auto& gameObject : GetOwner()->GetScene()->GetGameObjects())
    {
        if (gameObject->GetType() == "Object")
        {
            SquareCollider* wallCollider = gameObject->GetComponent<SquareCollider>();
            Maths::Vector2f wallPosition = gameObject->GetPosition();
            if (SquareCollider::IsColliding(*collider, *wallCollider))
            {
                bool sameHeight = position.y + collider->GetHeight() - 5.f > wallPosition.y && position.y < wallPosition.y + wallCollider->GetHeight() - 5.f;
                if (sameHeight)
                {
                    if ((position.x + collider->GetWidth() > wallPosition.x && position.x < wallPosition.x))
                    {
                        collidingRight = true;
                    }
                    else if ((position.x < wallPosition.x + wallCollider->GetWidth() && position.x > wallPosition.x))
                    {
                        collidingLeft = true;
                    }
                    return;
                }
            }
        }
    }
    collidingRight = false;
    collidingLeft = false;
}

void Physics::Update(float _delta_time)
{
    IsCollidingAbove();
    IsLateralColliding();

    Maths::Vector2f position = GetOwner()->GetPosition();
    Maths::Vector2f velocity = GetOwner()->GetVelocity();

    if (IsGrounded())
    {
        velocity.y = 0;
    }
    else
    {
        velocity += (gravity / mass) * _delta_time;
    }

    position += velocity * _delta_time;

    GetOwner()->SetVelocity(velocity);
    GetOwner()->SetPosition(position);
}
