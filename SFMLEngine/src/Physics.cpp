#include "Physics.h"

// Constructeur de la classe Physics. Initialise les variables de collision a false.
Physics::Physics()
{
    isJumping = false;
    collidingLeft = false;
    collidingRight = false;
}

// Destructeur de la classe Physics.
Physics::~Physics()
{
}

// Methode pour verifier si l'objet est au sol. Renvoie vrai si l'objet est en collision avec un autre objet par le bas.
bool Physics::IsGrounded()
{
    Maths::Vector2f velocity = GetOwner()->GetVelocity();
    SquareCollider* collider = GetOwner()->GetComponent<SquareCollider>();
    Maths::Vector2f position = GetOwner()->GetPosition();

    // Parcourt tous les GameObjects de la scene.
    for (auto& gameObject : GetOwner()->GetScene()->GetGameObjects())
    {

        // Si le GameObject est un objet (et non un joueur ou un ennemi), verifie si le proprietaire de ce composant Physics est en collision avec lui.
        if (gameObject->GetType() == "Object")
        {
            SquareCollider* groundCollider = gameObject->GetComponent<SquareCollider>();
            if (collider && groundCollider)
            {

                // Si le proprietaire est en collision avec l'objet et est au-dessus de l'objet, met a jour la position du proprietaire pour qu'il soit juste au-dessus de l'objet, arrête le saut et renvoie vrai.
                bool aboveGround = GetOwner()->GetPosition().y + collider->GetHeight() - 0.5f < gameObject->GetPosition().y;

                // Verifie si le joueur est sur la même tranche de position x que l'objet
                bool sameXRange = (position.x + collider->GetWidth() > gameObject->GetPosition().x) && (position.x < gameObject->GetPosition().x + groundCollider->GetWidth());
                if (SquareCollider::IsColliding(*collider, *groundCollider) && aboveGround && sameXRange)
                {
					GetOwner()->SetVelocity(Maths::Vector2f(velocity.x, 0.0f));
                    GetOwner()->SetPosition(Maths::Vector2f(position.x, gameObject->GetPosition().y - collider->GetHeight()));
                    SetJumping(false);
                    return true;
                }
            }
        }
    }

    // Si le proprietaire n'est en collision avec aucun objet par le bas, renvoie faux.
    return false;
}

// Methode pour verifier si l'objet est en collision par le haut. Renvoie vrai si l'objet est en collision avec un autre objet par le haut.
bool Physics::IsCollidingAbove()
{
    Maths::Vector2f velocity = GetOwner()->GetVelocity();
    SquareCollider* collider = GetOwner()->GetComponent<SquareCollider>();
    Maths::Vector2f position = GetOwner()->GetPosition();

    // Parcourt tous les GameObjects de la scene.
    for (auto& gameObject : GetOwner()->GetScene()->GetGameObjects())
    {

        // Si le GameObject est un objet (et non un joueur ou un ennemi), verifie si le proprietaire de ce composant Physics est en collision avec lui.
        if (gameObject->GetType() == "Object")
        {
            SquareCollider* objectCollider = gameObject->GetComponent<SquareCollider>();
            if (collider && objectCollider)
            {
                bool underObject = position.y > (gameObject->GetPosition().y + objectCollider->GetHeight() - 1);

                // Si le proprietaire est en collision avec l'objet et est en dessous de l'objet, met a jour la velocite et la position du proprietaire pour qu'il soit juste en dessous de l'objet et renvoie vrai.
                if (SquareCollider::IsColliding(*collider, *objectCollider) && underObject)
                {
                    GetOwner()->SetPosition(Maths::Vector2f(position.x, gameObject->GetPosition().y + objectCollider->GetHeight() + 1.0f));
                    return true;
                }
            }
        }
    }

    // Si le proprietaire n'est en collision avec aucun objet par le haut, renvoie faux.
    return false;
}

// Methode pour verifier si l'objet est en collision lateralement.
void Physics::IsLateralColliding()
{
    Maths::Vector2f velocity = GetOwner()->GetVelocity();
    SquareCollider* collider = GetOwner()->GetComponent<SquareCollider>();
    Maths::Vector2f position = GetOwner()->GetPosition();

    // Parcourt tous les GameObjects de la scene.
    for (auto& gameObject : GetOwner()->GetScene()->GetGameObjects())
    {

        // Si le GameObject est un objet (et non un joueur ou un ennemi), verifie si le proprietaire de ce composant Physics est en collision avec lui.
        if (gameObject->GetType() == "Object")
        {
            SquareCollider* wallCollider = gameObject->GetComponent<SquareCollider>();
            Maths::Vector2f wallPosition = gameObject->GetPosition();
            if (SquareCollider::IsColliding(*collider, *wallCollider))
            {

                // Si le proprietaire est en collision avec l'objet et est a la même hauteur que l'objet, verifie de quel côte le proprietaire est en collision avec l'objet et met a jour les variables de collision laterale en consequence.
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

    // Si le proprietaire n'est en collision avec aucun objet lateralement, met les variables de collision laterale a false.
    collidingRight = false;
    collidingLeft = false;
}

// Methode pour mettre a jour le composant Physics.
void Physics::Update(float _delta_time)
{

    // Verifie les collisions par le haut et lateralement.
    IsCollidingAbove();
    IsLateralColliding();

    Maths::Vector2f position = GetOwner()->GetPosition();
    Maths::Vector2f velocity = GetOwner()->GetVelocity();

    // Si le proprietaire est au sol, sa vitesse verticale est nulle. Sinon, ajoute la gravite a la vitesse verticale.
    if (IsGrounded())
    {
        velocity.y = 0;
    }
    else
    {
        velocity += (gravity / mass) * _delta_time;
    }

    // Met a jour la position et la vitesse du proprietaire.
    position += velocity * _delta_time;
    GetOwner()->SetVelocity(velocity);
    GetOwner()->SetPosition(position);
}

