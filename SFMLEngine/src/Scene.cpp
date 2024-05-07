#include "Scene.h"

#include <SFML/Graphics/RenderWindow.hpp>

Scene::Scene(const std::string& _name)
{
	name = _name;
}

void Scene::Awake() const
{
	for (GameObject* const& game_object : gameObjects)
	{
		game_object->Awake();
	}
}

void Scene::Start() const
{
	for (GameObject* const& game_object : gameObjects)
	{
		game_object->Start();
	}
}

void Scene::PreRender() const
{
	for (GameObject* const& game_object : gameObjects)
	{
		game_object->PreRender();
	}
}

void Scene::OnGUI() const
{
	for (GameObject* const& game_object : gameObjects)
	{
		game_object->OnGUI();
	}
}

void Scene::PostRender() const
{
	for (GameObject* const& game_object : gameObjects)
	{
		game_object->PostRender();
	}
}

void Scene::OnDebug() const
{
	for (GameObject* const& game_object : gameObjects)
	{
		game_object->OnDebug();
	}
}

void Scene::OnDebugSelected() const
{
	for (GameObject* const& game_object : gameObjects)
	{
		game_object->OnDebugSelected();
	}
}

void Scene::Present() const
{
	for (GameObject* const& game_object : gameObjects)
	{
		game_object->Present();
	}
}

void Scene::OnEnable() const
{
	for (GameObject* const& game_object : gameObjects)
	{
		game_object->OnEnable();
	}
}

void Scene::OnDisable() const
{
	for (GameObject* const& game_object : gameObjects)
	{
		game_object->OnDisable();
	}
}

void Scene::Destroy() const
{
	for (GameObject* const& game_object : gameObjects)
	{
		game_object->Destroy();
	}
}

void Scene::Finalize() const
{
	for (GameObject* const& game_object : gameObjects)
	{
		game_object->Finalize();
	}
}

void Scene::Update(const float _delta_time) const
{
	for (GameObject* const& game_object : gameObjects)
	{
		game_object->Update(_delta_time);
	}
}

void Scene::Render(sf::RenderWindow* _window)
{
	for (Background* const& background : backgrounds)
	{
		sf::Sprite sprite = background->GetSprite();
		_window->draw(sprite);
	}

	for (GameObject* const& game_object : gameObjects)
	{
		game_object->Render(_window);
	}
}

const std::string& Scene::GetName() const
{
	return name;
}

GameObject* Scene::CreateInGameObject(const std::string& _name, const std::string& _type, Maths::Vector2f _position, Maths::Vector2f _size, float _mass, const sf::Color _color)
{
	GameObject* game_object = CreateGameObject(_name, _type, id);
	game_object->SetPosition(Maths::Vector2f(_position));

	SquareCollider* square_collider = game_object->CreateComponent<SquareCollider>();
	square_collider->SetWidth(_size.x);
	square_collider->SetHeight(_size.y);

	RectangleShapeRenderer* shape_renderer = game_object->CreateComponent<RectangleShapeRenderer>();
	shape_renderer->SetColor(_color);
	shape_renderer->SetSize(_size);

	if (game_object->GetName() == "Player")
	{
		AnimatedSpriteComponent* animated_sprite = game_object->CreateComponent<AnimatedSpriteComponent>();
		animated_sprite->SetFrameCount(8);
		animated_sprite->SetFrameTime(0.1f);
		animated_sprite->LoadTexture("Assets/Run.png");

		// Calcule l'�chelle en fonction de la taille du gameObject et du sprite (_size *taille du gameObject* / _sprite *taille du sprite*)
		float scaleX = (_size.x / 30.0f);
		float scaleY = (_size.y / 30.0f);

		// D�finis l'�chelle du sprite
		animated_sprite->GetSprite()->setScale(scaleX, scaleY);
		animated_sprite->SetDefaultScale(scaleX, scaleY);

		Health* health = game_object->CreateComponent<Health>();
		health->SetMaxHealth(100);
		health->SetHealth(100);
	}

	if (game_object->GetType() == "Entity")
	{
		Physics* physics = game_object->CreateComponent<Physics>();
		if (game_object->GetName() == "Player")
		{
			physics->SetMass(0.5f);
		}
	}


	game_object->SetScene(this);
	game_object->SetBackgrounds(backgrounds);

	id++;

	return game_object;
}

GameObject* Scene::CreateGameObject(const std::string& _name, const std::string& _type, const int id)
{
	GameObject* const game_object = new GameObject();
	game_object->SetName(_name);
	game_object->SetType(_type);
	game_object->SetId(id);
	gameObjects.push_back(game_object);

	return game_object;
}

void Scene::CreateBackgrounds(const std::string& _path)
{
	for (int i = 0; i < 2; i++)
	{
		Background* const background = new Background();
		background->SetPath(_path, i);
		SetBackgroundSize(background, 1600.0f, 900.0f);

		if (i == 0)
		{
			background->SetPosition(0, 0);
		}
		else
		{
			background->SetPosition(1600.0f, 0);
		}

		backgrounds.push_back(background);
	}
}

void Scene::SetBackgroundSize(Background* background, float _width, float _height)
{
	background->SetSize(_width, _height);
}

void Scene::DestroyGameObject(const GameObject* _game_object)
{
	for (std::vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it)
	{
		if (*it == _game_object)
		{
			gameObjects.erase(it);
			delete _game_object;
			return;
		}
	}
}

GameObject* Scene::FindGameObject(const std::string& _name) const
{
	for (GameObject* const& game_object : gameObjects)
	{
		if (game_object->GetName() == _name)
		{
			return game_object;
		}
	}
	return nullptr;
}

GameObject* Scene::FindGameObjectType(const std::string& _type) const
{
	for (GameObject* const& game_object : gameObjects)
	{
		if (game_object->GetType() == _type)
		{
			return game_object;
		}
	}
	return nullptr;
}

const std::vector<GameObject*>& Scene::GetGameObjects() const
{
	return gameObjects;
}
