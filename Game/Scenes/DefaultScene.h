#pragma once

#include "GameObject.h"
#include "Player.h"

class DefaultScene final : public Scene
{
public:
	DefaultScene() : Scene("DefaultScene")
	{
		GameObject* player = CreateInGameObject("Player", Maths::Vector2f(300.f, 500.0f), Maths::Vector2f(40.f, 40.0f), 1.0f, sf::Color::Red);
		player->CreateComponent<Player>();

		GameObject* enemy = CreateInGameObject("Ground", Maths::Vector2f(0.f, 800.0f), Maths::Vector2f(1600.f, 100.0f), 1.0f, sf::Color::Blue);
		GameObject* enemy2 = CreateInGameObject("Enemy2", Maths::Vector2f(0.f, 0.0f), Maths::Vector2f(100.f, 100.0f), 1.0f, sf::Color::Green);
	}
};
