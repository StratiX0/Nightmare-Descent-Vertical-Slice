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

    // Methode pour infliger des degâts a l'objet. Reduit la sante actuelle de l'objet de la quantite specifiee.
    void TakeDamage(int amount);

    // Methode pour soigner l'objet. Augmente la sante actuelle de l'objet de la quantite specifiee.
    void Heal(int amount);

    // Methode pour verifier si l'objet est mort. Renvoie vrai si la sante actuelle de l'objet est inferieure ou egale a zero.
    bool IsDead() const;

    // Methodes pour obtenir et definir la sante actuelle de l'objet.
    int GetHealth() const;
    void SetHealth(int _health);

    // Methodes pour obtenir et definir la sante maximale de l'objet.
    int GetMaxHealth() const;
    void SetMaxHealth(int _maxHealth);

private:

    // Variables pour stocker la sante actuelle et maximale de l'objet.
    int currentHealth;
    int maxHealth;
};

