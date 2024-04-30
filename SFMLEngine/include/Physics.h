#pragma once

#include "Component.h"
#include "Components/SquareCollider.h"
#include "Scene.h"

class Physics : public Component
{
public:
	Physics();
	~Physics() override;

	bool IsGrounded();
	bool IsJumping() { return isJumping; }
	void SetJumping(bool _isJumping) { isJumping = _isJumping; }
	float GetMass() { return mass; }
	void SetMass(float _mass) { mass = _mass; }
	void Update(float _delta_time) override;

private:

	Maths::Vector2f gravity = Maths::Vector2f(0.0f, 1000.0f);
	bool isJumping;
	float mass = 1.0f;

};