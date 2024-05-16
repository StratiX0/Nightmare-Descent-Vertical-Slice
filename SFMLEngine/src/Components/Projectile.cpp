#include "Components/Projectile.h"

// Constructeur de la classe Projectile.
Projectile::Projectile()
{
}

// Destructeur de la classe Projectile.
Projectile::~Projectile()
{
}

bool Projectile::IsColliding()
{
    // Recupere le GameObject proprietaire de ce composant (le projectile).
    GameObject* projectile = GetOwner();

    // Recupere le SquareCollider du projectile.
    SquareCollider* projectileCollider = projectile->GetComponent<SquareCollider>();

    // Parcourt tous les GameObjects dans la scene.
    for (auto& gameObject : projectile->GetScene()->GetGameObjects())
    {
        // Si le GameObject actuel est un ennemi
        if (gameObject->GetType() == "Player")
        {
            // Recupere le SquareCollider de l'ennemi.
            SquareCollider* playerCollider = gameObject->GetComponent<SquareCollider>();

            // Si le projectile est en collision avec l'ennemi, inflige des degâts de collision.
            if (SquareCollider::IsColliding(*projectileCollider, *playerCollider))
            {
                gameObject->GetComponent<Health>()->TakeDamage(damage);
                return true; // Return after destroying the projectile to avoid accessing it later in the loop.
            }
        }
        else if (gameObject->GetType() == "Object")
        {
            // Recupere le SquareCollider de l'objet.
            SquareCollider* objectCollider = gameObject->GetComponent<SquareCollider>();

            // Si le projectile est en collision avec l'objet, detruit le projectile.
            if (SquareCollider::IsColliding(*projectileCollider, *objectCollider))
            {
                return true; // Return after destroying the projectile to avoid accessing it later in the loop.
            }
        }
    }
    return false;
}

// Methode pour mettre a jour le composant Projectile.
void Projectile::Update(float _delta_time)
{
    // Recupere le GameObject proprietaire de ce composant (le projectile).
    GameObject* projectile = GetOwner();

    if (GetOwner()->GetScene()->FindGameObjectType("Player") != nullptr)
    {
        GameObject* player = GetOwner()->GetScene()->FindGameObjectType("Player");

        bool outOfBounds = player->GetPosition().x - projectile->GetPosition().x <= -800 - projectile->GetComponent<SquareCollider>()->GetWidth() || projectile->GetPosition().x - player->GetPosition().x <= -800 - projectile->GetComponent<SquareCollider>()->GetWidth();

        if (outOfBounds || IsColliding())
        {
            projectile->MarkForDeletion();
            return;
        }
    }

    // Met a jour la position du projectile en fonction de sa vitesse et de sa direction.
    Maths::Vector2<float> position = projectile->GetPosition();
    position.x += speed * _delta_time;
    projectile->SetPosition(position);
}