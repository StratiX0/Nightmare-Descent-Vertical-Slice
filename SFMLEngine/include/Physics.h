#pragma once

#include "Component.h"
#include "Components/SquareCollider.h"
#include "Scene.h"

class Physics : public Component
{
public:
	Physics();
	~Physics() override;

	void Update(float _delta_time) override;
	bool IsGrounded();

private:

	Maths::Vector2f gravity = Maths::Vector2f(0.0f, 100.0f);

};