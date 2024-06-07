#include "Components/EnemyAttack.h"

// Constructeur par defaut de la classe PlayerAttack.
EnemyAttack::EnemyAttack()
{
	stopToShoot = false;
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

    if (enemy->GetScene()->FindGameObjectType("Player") != nullptr)
    {
        // Parcourt tous les GameObjects dans la scene.
        GameObject* player = enemy->GetScene()->FindGameObjectType("Player");
        // Recupere le SquareCollider de l'ennemi.
        SquareCollider* playerCollider = player->GetComponent<SquareCollider>();
        bool isPlayerAbove = player->GetPosition().y + playerCollider->GetHeight() - 0.5f < enemy->GetPosition().y;
        // Si le GameObject actuel est un ennemi, Si le joueur est en collision avec l'ennemi, inflige des degâts de collision.
        if (SquareCollider::IsColliding(*enemyCollider, *playerCollider) && !isPlayerAbove)
        {
            if (player->GetComponent<Physics>()->IsAttacking()) {

            }
            else if (!player->GetComponent<Physics>()->IsAttacking()) {
                InflictCollisionDamage(enemyCollider, playerCollider);
            }            
        }
    }


}

// Méthode pour envoyer un projectile.
void EnemyAttack::SendProjectile()
{
    // Verifie si un GameObject de type "Player" existe dans la scène.
    if (GetOwner()->GetScene()->FindGameObjectType("Player") != nullptr)
    {
        // Recupere le GameObject de type "Player".
        GameObject* player = GetOwner()->GetScene()->FindGameObjectType("Player");

        // Détermine la vitesse du projectile en fonction de la position du joueur par rapport à l'ennemi.
        float speed;
        if (player->GetPosition().x < GetOwner()->GetPosition().x)
        {
            speed = -700.0f;
        }
        else
        {
            speed = 700.0f;
        }

        // Dzfinit la taille du projectile.
        Maths::Vector2f size = Maths::Vector2f(40.0f, 20.0f);

        // Recupere la position de l'ennemi.
        Maths::Vector2f ownerPosition = GetOwner()->GetPosition();

        // Ajuste la position y du projectile pour qu'il soit centre sur l'ennemi.
        ownerPosition.y = ownerPosition.y + (GetOwner()->GetComponent<SquareCollider>()->GetHeight() / 2.0f) - (size.y / 2.0f);

        // Cree le projectile et l'ajoute à la scène.
        GameObject* projectile = GetOwner()->GetScene()->CreateProjectile("Projectile", "Projectile", ownerPosition, size, 10.0f, speed, sf::Color::Transparent);
    }
}

// Methode pour mettre à jour le PlayerAttack.
void EnemyAttack::Update(float _delta_time)
{

    // Verifie si le joueur est en collision avec un ennemi.
    IsColliding();

    if (GetOwner()->GetName() == "Wizard")
    {
        if (projectileTimer < 0.5f && projectileTimer > 0.0f)
        {
            stopToShoot = true;
        }
        else if (projectileTimer <= 2.5f && projectileTimer > 0.5f)
        {
            stopToShoot = false;
        }

        if (projectileTimer <= 0.0f)
        {
            SendProjectile();
            projectileTimer = 3.0f;
        }
        projectileTimer -= _delta_time;
    }
    
}
