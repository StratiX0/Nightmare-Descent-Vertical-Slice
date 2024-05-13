#pragma once

#include "Component.h"
#include "Components/SquareCollider.h"
#include "Scene.h"

// La classe EnemyAttack herite de la classe Component et represente les proprietes physiques d'un GameObject dans votre jeu.
class EnemyAttack : public Component
{
public:
	EnemyAttack();
	~EnemyAttack();

	// Methode pour infliger des degats en cas de collision.
	void InflictCollisionDamage(SquareCollider* playerCollider, SquareCollider* enemyCollider);

	// Methode pour verifier si l'objet est en collision avec un autre objet.
	void IsColliding();

	// Methode pour definir les degats infliges par collision au joueur.
	void SetCollisionDamage(float _collisionDamage) { collisionDamage = _collisionDamage; }

	void SendProjectile();

	// Methode pour mettre a jour le composant Attack.
	void Update(float _delta_time) override;

private:

	// Degats infliges par collision au joueur.   
	float collisionDamage;

	float projectileTimer;

	std::string name;
};