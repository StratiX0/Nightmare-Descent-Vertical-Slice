#pragma once

#include "GameObject.h"
#include "Player.h"
#include "RectangleShapeRenderer.h"
#include "Scene.h"
#include "SquareCollider.h"

int id = 0;

class DefaultScene final : public Scene
{
public:
	DefaultScene() : Scene("DefaultScene")
	{
		GameObject* player = CreaInGameObject("Player", Maths::Vector2f(200.f,200.0f), Maths::Vector2f(20.f, 20.0f), sf::Color::Red);
		player->CreateComponent<Player>();

		GameObject* enemy = CreaInGameObject("Enemy", Maths::Vector2f(400.f, 400.0f), Maths::Vector2f(10.f, 10.0f), sf::Color::Blue);
		GameObject* enemy2 = CreaInGameObject("Enemy2", Maths::Vector2f(0.f, 0.0f), Maths::Vector2f(50.f, 50.0f), sf::Color::Green);
	}

	GameObject* CreaInGameObject(const std::string& _name, Maths::Vector2f _position, Maths::Vector2f _size, const sf::Color _color)
	{
		GameObject* game_object = CreateGameObject(_name, id);
		game_object->SetPosition(Maths::Vector2f(_position));

		SquareCollider* square_collider = game_object->CreateComponent<SquareCollider>();
		square_collider->SetWidth(_size.x);
		square_collider->SetHeight(_size.y);

		RectangleShapeRenderer* shape_renderer = game_object->CreateComponent<RectangleShapeRenderer>();
		shape_renderer->SetColor(_color);
		shape_renderer->SetSize(_size);

		id++;

		return game_object;
	}
};
