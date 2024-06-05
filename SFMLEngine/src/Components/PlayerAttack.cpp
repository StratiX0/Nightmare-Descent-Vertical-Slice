#include "Components/PlayerAttack.h"

// Constructeur par defaut de la classe PlayerAttack.
PlayerAttack::PlayerAttack()
{
}

// Destructeur de la classe PlayerAttack.
PlayerAttack::~PlayerAttack()
{
}


// Methode pour infliger des degâts de collision à un ennemi.
void PlayerAttack::InflictAttackDamage(SquareCollider* playerCollider, SquareCollider* enemyCollider)
{

    // Recupere le GameObject proprietaire de ce composant (le joueur) et l'ennemi.
    GameObject* player = GetOwner();
    GameObject* enemy = enemyCollider->GetOwner();

    // Verifie si le joueur attaque.
    Health* playerHealth = player->GetComponent<Health>();
    if (player->GetComponent<Physics>()->IsAttacking())
    {
        // Si le joueur est au-dessus de l'ennemi, inflige des degâts à l'ennemi.
        Health* enemyHealth = enemy->GetComponent<Health>();
        enemyHealth->TakeDamage(collisionDamage);
        playerHealth->SetInvincibilityTime(1.0f);
		if (enemy->GetName() == "Wanderer")
        {
			player->GetComponent<Score>()->IncrementScore(25);
		}
        if (enemy->GetName() == "Wizard")
        {
            player->GetComponent<Score>()->IncrementScore(50);
        }
        if (enemy->GetName() == "Boss")
        {
            player->GetComponent<Score>()->IncrementScore(100);
        }
    }
}

// Methode pour verifier si le joueur est en collision avec un ennemi.
void PlayerAttack::IsColliding()
{

    // Recupere le GameObject proprietaire de ce composant (le joueur).
    GameObject* player = GetOwner();

    // Recupere le SquareCollider du joueur.
    SquareCollider* playerCollider = player->GetComponent<SquareCollider>();

    // Parcourt tous les GameObjects dans la scene.
    for (auto& gameObject : player->GetScene()->GetGameObjects())
    {

        // Si le GameObject actuel est un ennemi
        if (gameObject->GetType() == "Enemy")
        {
            // Recupere le SquareCollider de l'ennemi.
            SquareCollider* enemyCollider = gameObject->GetComponent<SquareCollider>();

            // Si le joueur est en collision avec l'ennemi, inflige des degâts de collision.
            if (SquareCollider::IsColliding(*playerCollider, *enemyCollider) && player->GetComponent<Health>()->GetInvincibilityTime() == 0)
            {
                InflictAttackDamage(playerCollider, enemyCollider);
            }
        }
    }
}

// Methode pour mettre à jour le PlayerAttack.
void PlayerAttack::Update(float _delta_time)
{

    // Verifie si le joueur est en collision avec un ennemi.
    IsColliding();
}
