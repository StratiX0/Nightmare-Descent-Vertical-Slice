#pragma once

#include "Component.h"
#include "Components/SquareCollider.h"
#include "Scene.h"

// La classe Projectile herite de la classe Component et represente les proprietes physiques d'un GameObject dans votre jeu.
class Projectile : public Component
{
public:

	// Constructeur et destructeur de la classe Projectile.
	Projectile();
	~Projectile();

	// Methode pour definir la vitesse du projectile.
	void SetSpeed(float _speed) { speed = _speed; }

	// Methode pour infliger des degâts en cas de collision.
	void SetDamage(float _damage) { damage = _damage; }

	// Methode pour verifier si l'objet est en collision avec un autre objet.
	bool IsColliding();

	// Methode pour mettre a jour le composant Attack.
	void Update(float _delta_time) override;

private:

	// Vitesse du projectile.
	float speed;

	// Degats infliges par collision.
	float damage;

};