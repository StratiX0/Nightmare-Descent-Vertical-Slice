#pragma once

#include "Component.h"
#include "Components/SquareCollider.h"
#include "Scene.h"

// La classe Physics herite de la classe Component et represente les proprietes physiques d'un GameObject dans le jeu.
class Physics : public Component
{
public:

    // Constructeur et destructeur de la classe Physics.
    Physics();
    ~Physics() override;

    // Methode pour verifier si l'objet est au sol.
    bool IsGrounded();

    // Methode pour verifier si l'objet est en collision par le haut.
    bool IsCollidingAbove();

    // Methode pour verifier si l'objet est en collision lateralement.
    void IsLateralColliding();

    // Methodes pour obtenir et definir si l'objet est en train de sauter.
    bool IsJumping() { return isJumping; }
    void SetJumping(bool _isJumping) { isJumping = _isJumping; }

    // Methodes pour obtenir et definir si l'objet est en train de d'attaquer.
    bool IsAttacking() { return isAttack; }
    void SetAttack(bool _isAttack) { isAttack = _isAttack; }

    // Methodes pour obtenir et definir si la porte est en collision.
    bool DoorIsColliding() { return DoorColliding; }
    void SetDoorIsColliding(bool _DoorIsColliding) { DoorColliding = _DoorIsColliding; }

    // Methodes pour obtenir et definir si la porte a été atteinte.
    bool DoorIsReached() { return DoorReached; }
    void SetDoorIsReached(bool _DoorIsReached) { DoorReached = _DoorIsReached; }

    // Methodes pour obtenir et definir si la porte a été atteinte.
    bool DoorIsOpen() { return DoorOpen; }
    void SetDoorIsOpen(bool _DoorIsOpen) { DoorOpen = _DoorIsOpen; }

    // Methodes pour obtenir et definir la masse de l'objet.
    float GetMass() { return mass; }
    void SetMass(float _mass) { mass = _mass; }

	// Methode pour effectuer un saut.
	void Jump();


    // Methode pour mettre a jour le composant Physics.
    void Update(float _delta_time) override;

	// Methode pour appliquer une force a l'objet.
	void ApplyForce(const Maths::Vector2f& _force);


    // Variable pour stocker la gravite appliquee a l'objet.
    Maths::Vector2f gravity = Maths::Vector2f(0.0f, 1500.0f);

    // Variables pour verifier si l'objet est en collision a gauche ou a droite.
    bool collidingLeft;
    bool collidingRight;

private:
    // Variable pour verifier si l'objet est en train de sauter.
    bool isJumping;
    bool isAttack = false;
    bool DoorColliding = false;
    bool DoorReached = false;
    bool DoorOpen = false;

    // Variable pour stocker la masse de l'objet.
    float mass = 1.0f;
};
