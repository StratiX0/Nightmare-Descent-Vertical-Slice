#include "Components/Projectile.h"

// Constructeur de la classe Projectile.
Projectile::Projectile()
{
}

// Destructeur de la classe Projectile.
Projectile::~Projectile()
{
}

void Projectile::IsColliding()
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
				projectile->~GameObject();
			}
		}
		else if (gameObject->GetType() == "Object")
		{
			// Recupere le SquareCollider de l'objet.
			SquareCollider* objectCollider = gameObject->GetComponent<SquareCollider>();

			// Si le projectile est en collision avec l'objet, detruit le projectile.
			if (SquareCollider::IsColliding(*projectileCollider, *objectCollider))
			{
				projectile->~GameObject();
			}
		}
	}
}

// Methode pour mettre a jour le composant Projectile.
void Projectile::Update(float _delta_time)
{
	IsColliding();

    // Recupere le GameObject proprietaire de ce composant (le projectile).
    GameObject* projectile = GetOwner();

    // Met a jour la position du projectile en fonction de sa vitesse et de sa direction.
    Maths::Vector2<float> position = projectile->GetPosition();
    position.x += speed * _delta_time;
    projectile->SetPosition(position);
}