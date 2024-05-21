// Boss.cpp
#include "Boss.h"
#include "Components/Projectile.h"
#include "Components/SquareCollider.h"
#include "Components/Health.h"
#include "Player.h"

Boss::Boss()
{
    // Initialize collider and health here
    // You can adjust the size of the collider to fit your boss sprite
    collider = new SquareCollider();
    health = new Health();
    health->SetMaxHealth(10); // Boss disappears after 10 hits
}

Boss::~Boss()
{
    delete collider;
    delete health;
}

void Boss::Update(const float _delta_time)
{
    // Update dash cooldown
    dashCooldown -= _delta_time;
    if (dashCooldown <= 0)
    {
        Dash();
        ShootProjectile();
        dashCooldown = 5.0f;
    }

    // Randomly decide whether to jump
    if (rand() / (float)RAND_MAX < jumpProbability)
    {
        Jump();
    }

    // Obtenez une référence au joueur
    Player* player = dynamic_cast<Player*>(GetScene()->FindGameObjectByName("Player"));
    if (player != nullptr)
    {
        // Vérifiez si le boss a été touché par le joueur
        if (collider->CheckCollision(player->GetCollider()))
        {
            OnHit();
        }
    }

    // Check if the boss should disappear
    if (health->GetCurrentHealth() <= 0)
    {
        // Display game over screen
    }
}

void Boss::Dash()
{
}

void Boss::Jump()
{
}

void Boss::ShootProjectile()
{
}

void Boss::OnHit()
{
    hitCount++;
    health->TakeDamage(1); // Assume each hit deals 1 damage
}
