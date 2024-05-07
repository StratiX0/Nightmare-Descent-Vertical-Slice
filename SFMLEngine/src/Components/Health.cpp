#include "Components/Health.h"

Health::Health()
{
	currentHealth = 100;
	maxHealth = 100;
}


Health::~Health()
{
}

void Health::TakeDamage(int amount)
{
    currentHealth -= amount;
    if (currentHealth < 0)
    {
        currentHealth = 0;
    }
}

void Health::Heal(int amount)
{
    currentHealth += amount;
    if (currentHealth > maxHealth)
    {
        currentHealth = maxHealth;
    }
}

bool Health::IsDead() const
{
    return currentHealth <= 0;
}

void Health::SetHealth(int _health)
{
	currentHealth = _health;
}

int Health::GetHealth() const
{
    return currentHealth;
}

int Health::GetMaxHealth() const
{
    return maxHealth;
}

void Health::SetMaxHealth(int _maxHealth)
{
	maxHealth = _maxHealth;
}
