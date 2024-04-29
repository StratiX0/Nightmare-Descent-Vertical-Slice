#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "GameObject.h"
#include "Components/RectangleShapeRenderer.h"
#include "Scene.h"
#include "Components/SquareCollider.h"
#include "AnimatedSprite.h"
#include "Physics.h"
#include "Background.h"

class Scene
{
public:
	explicit Scene(const std::string& _name);
	virtual ~Scene() = default;

	void Awake() const;
	void Start() const;
	void Update(float _delta_time) const;

	void PreRender() const;
	void Render(sf::RenderWindow* _window);
	void OnGUI() const;
	void OnDebug() const;
	void OnDebugSelected() const;
	void PostRender() const;
	void Present() const;

	void OnEnable() const;
	void OnDisable() const;

	void Destroy() const;
	void Finalize() const;

	const std::string& GetName() const;

	GameObject* CreateInGameObject(const std::string& _name, Maths::Vector2f _position, Maths::Vector2f _size, float _mass, const sf::Color _color);

	GameObject* CreateGameObject(const std::string& _name, const int id);
	void DestroyGameObject(const GameObject* _game_object);
	GameObject* FindGameObject(const std::string& _name) const;
	const std::vector<GameObject*>& GetGameObjects() const;

	void SetBackground(const std::string& _path) { background.SetPath(_path); }
	void SetBackgroundSize(sf::RenderWindow* _window) { background.SetSize(_window); }

private:
	std::string name;
	std::vector<GameObject*> gameObjects;
	int id = 0;
	Background background;
};
