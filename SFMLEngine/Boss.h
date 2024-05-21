#pragma once
#include "Component.h"
#include "Components/Projectile.h"
#include "Components/SquareCollider.h"
#include "Components/Health.h"

class Boss : public Component
{
public:
    Boss();
    ~Boss();

    void Update(const float _delta_time) override;
    void Dash();
    void Jump();
    void ShootProjectile();
    void OnHit();

private:
    float dashCooldown = 5.0f;
    float jumpProbability = 0.1f; // 10% chance to jump
    int hitCount = 0;
    SquareCollider* collider;
    Health* health;
};