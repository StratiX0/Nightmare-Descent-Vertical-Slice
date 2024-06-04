#pragma once

#include "Component.h"
#include "Components/SquareCollider.h"
#include "Scene.h"

// La classe PlayerAttack herite de la classe Component et represente les proprietes physiques d'un GameObject dans votre jeu.
class PlayerAttack : public Component
{
public:

    // Constructeur et destructeur de la classe PlayerAttack.
	PlayerAttack();
    ~PlayerAttack() override;

	// Methode pour infliger des degâts en cas de collision.
	void InflictAttackDamage(SquareCollider* playerCollider, SquareCollider* enemyCollider);

	// Methode pour verifier si l'objet est en collision avec un autre objet.
	void IsColliding();

	// Methode pour definir les degâts infliges par collision avec l'ennemie.
	void SetCollisionDamage(float _collisionDamage) { collisionDamage = _collisionDamage; }

	// Methode pour mettre a jour le composant Attack.
	void Update(float _delta_time) override;
   

private:

	// Degâts infliges par collision avec l'ennemie.   
	float collisionDamage; 
};
