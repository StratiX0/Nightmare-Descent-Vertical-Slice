#pragma once

#include "Component.h"
#include "Scene.h"

// La classe Health herite de la classe Component et represente la sante d'un GameObject dans votre jeu.
class Health : public Component
{
public:

    // Constructeur et destructeur de la classe Health.
    Health();
    ~Health();

    // Methode pour infliger des degâts. Reduit la sante actuelle avec la quantite specifiee.
    void TakeDamage(float amount);

    // Methode pour soigner l'entite. Augmente la sante actuelle avec la quantite specifiee.
    void Heal(int amount);

    // Methode pour verifier si l'entite est morte. Renvoie vrai si la sante actuelle est inferieure ou egale a zero.
    bool IsDead() const;

    // Methodes pour obtenir et definir la sante actuelle.
    float GetHealth() const;
    void SetHealth(float _health);

    // Methodes pour obtenir et definir la sante maximale.
    float GetMaxHealth() const;
    void SetMaxHealth(float _maxHealth);

	// Methodes pour obtenir et definir le temps d'invincibilite.
	void SetInvincibilityTime(float _invincibilityTime) { invincibilityTime = _invincibilityTime; }
	float GetInvincibilityTime() { return invincibilityTime; }

    // Methode pour mettre a jour le composant Health.
    void Update(float _delta_time) override;

    // Méthode pour obtenir la santé actuelle.
    float GetCurrentHealth() const { return currentHealth; }
private:

    // Variables pour stocker la sante actuelle et maximale de l'entite.
    float currentHealth;
    float maxHealth;

	// Variable pour stocker le temps d'invincibilite.
	float invincibilityTime;
};

