#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "GameObject.h"
#include "Components/RectangleShapeRenderer.h"
#include "Scene.h"
#include "Components/SquareCollider.h"
#include "AnimatedSprite.h"
#include "Physics.h"
#include "Background.h"
#include "Components/Health.h"

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

	GameObject* CreateInGameObject(const std::string& _name, const std::string& _type, Maths::Vector2f _position, Maths::Vector2f _size, float _mass, const sf::Color _color);

	GameObject* CreateGameObject(const std::string& _name, const std::string& _type, const int id);
	void CreateBackgrounds(const std::string& _path);
	std::vector<Background*> GetBackgrounds() const { return backgrounds; }
	void SetBackgroundSize(Background* background, float _width, float _height);
	void DestroyGameObject(const GameObject* _game_object);
	GameObject* FindGameObject(const std::string& _name) const;
	GameObject* FindGameObjectType(const std::string& _type) const;
	const std::vector<GameObject*>& GetGameObjects() const;

private:
	std::string name;
	std::vector<GameObject*> gameObjects;
	int id = 0;
	std::vector<Background*> backgrounds;
};
