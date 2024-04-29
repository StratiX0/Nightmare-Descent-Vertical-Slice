#pragma once

#include "GameObject.h"
#include "Player.h"
#include "RectangleShapeRenderer.h"
#include "Scene.h"
#include "SquareCollider.h"
#include "AnimatedSprite.h"

int id = 0;

class DefaultScene final : public Scene
{
public:
	DefaultScene() : Scene("DefaultScene")
	{
		GameObject* player = CreaInGameObject("Player", Maths::Vector2f(300.f,300.0f), Maths::Vector2f(40.f, 40.0f), sf::Color::Red);
		player->CreateComponent<Player>();

		GameObject* enemy = CreaInGameObject("Enemy", Maths::Vector2f(400.f, 400.0f), Maths::Vector2f(10.f, 10.0f), sf::Color::Blue);
		GameObject* enemy2 = CreaInGameObject("Enemy2", Maths::Vector2f(0.f, 0.0f), Maths::Vector2f(100.f, 100.0f), sf::Color::Green);
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

		AnimatedSpriteComponent* animated_sprite = game_object->CreateComponent<AnimatedSpriteComponent>();
		animated_sprite->SetFrameCount(8);
		animated_sprite->SetFrameTime(0.1f);
		animated_sprite->LoadTexture("Assets/Run3.png");

		// Obtenez la taille du sprite après avoir chargé la texture
		sf::Vector2u spriteSize = animated_sprite->GetSprite()->getTexture()->getSize();

		// Calculez l'échelle en fonction de la taille du gameObject
		// Nous devons également prendre en compte l'échelle de base du sprite (1,1) et la taille correspondante du rectangle (25,40)
		float scaleX = (_size.x / 30.0f);
		float scaleY = (_size.y / 30.0f);

		// Définissez l'échelle du sprite
		animated_sprite->GetSprite()->setScale(scaleX, scaleY);


		id++;

		return game_object;
	}
};
