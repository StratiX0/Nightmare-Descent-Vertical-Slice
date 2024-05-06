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

		GameObject* player = CreateInGameObject("Player", "Entity", Maths::Vector2f(1600.0f / 2 - 40.0f / 2, -500.0f), Maths::Vector2f(40.f, 40.0f), 1.0f, sf::Color::Red);
		player->CreateComponent<Player>();

		/////////////////////////////////
		//  Create the ground objects  //
		/////////////////////////////////

		CreateInGameObject("Ground", "Object", Maths::Vector2f(0.0f, 700.0f), Maths::Vector2f(100.f, 900.0f), 1.0f, sf::Color::Transparent);
		CreateInGameObject("Ground", "Object", Maths::Vector2f(1400.0f, 0.0f), Maths::Vector2f(100.f, 900.0f), 1.0f, sf::Color::Transparent);
		CreateInGameObject("Ground", "Object", Maths::Vector2f(0.0f, 800.0f), Maths::Vector2f(1600.f, 100.0f), 1.0f, sf::Color::Transparent);
		CreateInGameObject("Ground", "Object", Maths::Vector2f(1800.0f, 800.0f), Maths::Vector2f(1600.f, 100.0f), 1.0f, sf::Color::Transparent);

		//////////////////////////////////
		// Create the platform objects //
		/////////////////////////////////

		CreateInGameObject("Platform", "Object", Maths::Vector2f(300.f, 675.0f), Maths::Vector2f(300.f, 50.0f), 1.0f, sf::Color::Green);
	}
};
