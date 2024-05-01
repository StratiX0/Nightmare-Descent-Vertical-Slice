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
                bool aboveGround = GetOwner()->GetPosition().y <= gameObject->GetPosition().y;
                if (SquareCollider::IsColliding(*collider, *groundCollider) && aboveGround)
                {
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
    // Vérifie si le gameObject est en contact avec un objet au-dessus de lui
    SquareCollider* collider = GetOwner()->GetComponent<SquareCollider>();
    for (auto& gameObject : GetOwner()->GetScene()->GetGameObjects())
    {
        if (gameObject->GetType() == "Object")
        {
            SquareCollider* wallCollider = gameObject->GetComponent<SquareCollider>();
            if (collider && wallCollider)
            {
                if (SquareCollider::IsColliding(*collider, *wallCollider) && (GetOwner()->GetPosition().y + collider->GetHeight() < wallCollider->GetOwner()->GetPosition().y))
                {
                    if (GetOwner()->GetPosition().y >= gameObject->GetPosition().y + collider->GetHeight())
                    {
                        // Ajuste la position du joueur s'il est en collision avec un objet au-dessus de lui
                        GetOwner()->SetPosition(Maths::Vector2f(GetOwner()->GetPosition().x, gameObject->GetPosition().y + collider->GetHeight()));
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void Physics::IsLateralColliding()
{
    // Vérifie si le gameObject est en contact avec un mur
    SquareCollider* collider = GetOwner()->GetComponent<SquareCollider>();
    Maths::Vector2f position = GetOwner()->GetPosition();
    Maths::Vector2f velocity = GetOwner()->GetVelocity();
    collidingRight = false;
    collidingLeft = false;
    for (auto& gameObject : GetOwner()->GetScene()->GetGameObjects())
    {
        if (gameObject->GetType() == "Object")
        {
            SquareCollider* wallCollider = gameObject->GetComponent<SquareCollider>();
            Maths::Vector2f wallPosition = gameObject->GetPosition();
            if (SquareCollider::IsColliding(*collider, *wallCollider) && position.y + collider->GetHeight() > wallPosition.y)
            {
                if (GetOwner()->GetComponent<AnimatedSpriteComponent>()->GetDirection() == AnimatedSpriteComponent::Right && position.x + collider->GetWidth() > wallPosition.x)
                {
                    position.x = wallPosition.x - collider->GetWidth();
                    collidingRight = true;
                }
                else if (GetOwner()->GetComponent<AnimatedSpriteComponent>()->GetDirection() == AnimatedSpriteComponent::Left && position.x < wallPosition.x + wallCollider->GetWidth())
                {
                    position.x = wallPosition.x + wallCollider->GetWidth();
                    collidingLeft = true;
                }
                GetOwner()->SetPosition(position);
                return;
            }
        }
    }
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
        velocity = Maths::Vector2f::Zero;
    }

    IsLateralColliding();

    //if (IsCollidingAbove())
    //{
    //    velocity.y = 0.0f;
    //}

    position += velocity * _delta_time;

    GetOwner()->SetVelocity(velocity);
    GetOwner()->SetPosition(position);
}
