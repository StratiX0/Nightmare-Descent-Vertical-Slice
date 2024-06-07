#pragma once

#include "Component.h"
#include "Components/SquareCollider.h"
#include "Scene.h"

// La classe PlayerAttack herite de la classe Component et represente les proprietes physiques d'un GameObject dans votre jeu.
class DoorGameObject : public Component
{
public:
	DoorGameObject();
	~DoorGameObject();

	bool CollidePlayer = false;

	// Methode pour verifier si l'objet est en collision avec un autre objet.
	void IsColliding();

	// Methode pour mettre a jour le composant Attack.
	void Update(float _delta_time) override;

private:
};
