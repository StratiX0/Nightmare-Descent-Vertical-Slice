#include "Components/EnemyAttack.h"

// Constructeur par defaut de la classe PlayerAttack.
EnemyAttack::EnemyAttack()
{
}

// Destructeur de la classe PlayerAttack.
EnemyAttack::~EnemyAttack()
{
}

// Methode pour infliger des degâts de collision à un ennemi.
void EnemyAttack::InflictCollisionDamage(SquareCollider* enemyCollider, SquareCollider* playerCollider)
{

    // Recupere le GameObject proprietaire de ce composant (le joueur) et l'ennemi.
    GameObject* enemy = GetOwner();
    GameObject* player = playerCollider->GetOwner();

    // Si le joueur est au-dessus de l'ennemi, inflige des degâts à l'ennemi et met le temps d'invincibilite.
    Health* playerHealth = player->GetComponent<Health>();
	if (playerHealth->GetInvincibilityTime() <= 0.0f)
    {
        playerHealth->TakeDamage(collisionDamage);
        playerHealth->SetInvincibilityTime(2.0f);
	}

}

// Methode pour verifier si le joueur est en collision avec un ennemi.
void EnemyAttack::IsColliding()
{

    // Recupere le GameObject proprietaire de ce composant (le joueur).
    GameObject* enemy = GetOwner();

    // Recupere le SquareCollider du joueur.
    SquareCollider* enemyCollider = enemy->GetComponent<SquareCollider>();

    // Parcourt tous les GameObjects dans la scene.
    GameObject* player = enemy->GetScene()->FindGameObjectType("Player");

    // Recupere le SquareCollider de l'ennemi.
    SquareCollider* playerCollider = player->GetComponent<SquareCollider>();

    bool isPlayerAbove = player->GetPosition().y + playerCollider->GetHeight() - 0.5f < enemy->GetPosition().y;
    // Si le GameObject actuel est un ennemi, Si le joueur est en collision avec l'ennemi, inflige des degâts de collision.
    if (SquareCollider::IsColliding(*enemyCollider, *playerCollider) && !isPlayerAbove)
    {
        InflictCollisionDamage(enemyCollider, playerCollider);
    }
}

// Methode pour mettre à jour le PlayerAttack.
void EnemyAttack::Update(float _delta_time)
{

    // Verifie si le joueur est en collision avec un ennemi.
    IsColliding();
}
