#pragma once

#include "GameObject.h"
#include "Player.h"
#include "Background.h"

class DefaultScene final : public Scene
{
public:
	DefaultScene() : Scene("DefaultScene")
	{
		CreateBackgrounds("Assets/Background2.png");

		GameObject* player = CreateInGameObject("Player", "Entity", Maths::Vector2f(300.f, 0.0f), Maths::Vector2f(40.f, 40.0f), 1.0f, sf::Color::Red);
		player->CreateComponent<Player>();

		GameObject* ground = CreateInGameObject("Ground", "Object", Maths::Vector2f(0.f, 800.0f), Maths::Vector2f(1600.f, 100.0f), 1.0f, sf::Color::Transparent);
		GameObject* platform = CreateInGameObject("Platform", "Object", Maths::Vector2f(300.f, 675.0f), Maths::Vector2f(300.f, 25.0f), 1.0f, sf::Color::Green);
	}
};
