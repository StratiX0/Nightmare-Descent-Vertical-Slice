#pragma once

#include "Component.h"
#include "Scene.h"

class Health : public Component
{
public:
    Health();

    ~Health();

    void TakeDamage(int amount);
    void Heal(int amount);
    bool IsDead() const;

    int GetHealth() const;
    void SetHealth(int _health);
    int GetMaxHealth() const;
    void SetMaxHealth(int _maxHealth);

private:
    int currentHealth;
    int maxHealth;
};
