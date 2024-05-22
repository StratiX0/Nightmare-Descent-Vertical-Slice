#include "Components/Health.h"

// Constructeur de la classe Health. Initialise la sante actuelle et maximale à 100.
Health::Health()
{
    currentHealth = 100;
    maxHealth = 100;
	invincibilityTime = 0.0f;
}

// Destructeur de la classe Health.
Health::~Health()
{
}

// Methode pour infliger des degâts à l'objet. Reduit la sante actuelle de l'objet de la quantite specifiee. Si la sante actuelle tombe en dessous de zero, elle est fixee à zero.
void Health::TakeDamage(float amount)
{
    currentHealth -= amount;
    if (currentHealth < 0)
    {
        currentHealth = 0;
    }
}

// Methode pour soigner l'objet. Augmente la sante actuelle de l'objet de la quantite specifiee. Si la sante actuelle depasse la sante maximale, elle est fixee à la sante maximale.
void Health::Heal(int amount)
{
    currentHealth += amount;
    if (currentHealth > maxHealth)
    {
        currentHealth = maxHealth;
    }
}

// Methode pour verifier si l'objet est mort. Renvoie vrai si la sante actuelle de l'objet est inferieure ou egale à zero.
bool Health::IsDead() const
{
    return currentHealth <= 0;
}

// Methode pour definir la sante actuelle de l'objet.
void Health::SetHealth(float _health)
{
    currentHealth = _health;
}

// Methode pour obtenir la sante actuelle de l'objet.
float Health::GetHealth() const
{
    return currentHealth;
}

// Methode pour obtenir la sante maximale de l'objet.
float Health::GetMaxHealth() const
{
    return maxHealth;
}

// Methode pour definir la sante maximale de l'objet.
void Health::SetMaxHealth(float _maxHealth)
{
    maxHealth = _maxHealth;
}

// Methode pour mettre à jour le Health.
void Health::Update(float _delta_time)
{
	if (GetOwner()->GetType() == "Player")
    {
        if (invincibilityTime > 0.0f)
        {
			invincibilityTime -= _delta_time;
			GetOwner()->GetComponent<AnimatedSpriteComponent>()->Blink(0.1f, _delta_time);
        }
		if (invincibilityTime < 0.0f)
		{
			invincibilityTime = 0.0f;
		}
        if (GetOwner()->GetComponent<AnimatedSpriteComponent>() != nullptr)
        {
            sf::Color color = GetOwner()->GetComponent<AnimatedSpriteComponent>()->GetSprite()->getColor();

            if ((color != sf::Color::White) && invincibilityTime <= 0.0f)
            {
                color = sf::Color::White; // Alterne entre complètement transparent (0) et complètement opaque (255)
                GetOwner()->GetComponent<AnimatedSpriteComponent>()->GetSprite()->setColor(color);
            }
        }
	}
}

