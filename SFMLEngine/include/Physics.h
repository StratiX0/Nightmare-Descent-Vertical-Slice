#pragma once

#include "Component.h"
#include "Components/SquareCollider.h"
#include "Scene.h"

// La classe Physics herite de la classe Component
// et represente les proprietes physiques d'un GameObject dans votre jeu.
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

    // Methodes pour obtenir et definir la masse de l'objet.
    float GetMass() { return mass; }
    void SetMass(float _mass) { mass = _mass; }

    // Methode pour mettre a jour le composant Physics.
    void Update(float _delta_time) override;

    // Variable pour stocker la gravite appliquee a l'objet.
    Maths::Vector2f gravity = Maths::Vector2f(0.0f, 1000.0f);

    // Variables pour verifier si l'objet est en collision a gauche ou a droite.
    bool collidingLeft;
    bool collidingRight;

private:
    // Variable pour verifier si l'objet est en train de sauter.
    bool isJumping;

    // Variable pour stocker la masse de l'objet.
    float mass = 1.0f;
};
