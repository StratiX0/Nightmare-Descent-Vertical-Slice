#pragma once
#include <string>
#include <vector>

#include "Component.h"
#include "Maths/Vector2.h"

class Component;
class Scene;
class Background;

class GameObject
{
public:
	GameObject() = default;
	~GameObject();

	std::string GetName() const { return name; }
	std::string GetType() const { return type; }
	int GetId() const { return id; }
	Maths::Vector2<float> GetPosition() const { return position; }
	Maths::Vector2<float> GetLastPosition() const { return position; }
	Maths::Vector2<float> GetVelocity() const { return velocity; }
	float GetRotation() const { return rotation; }
	Maths::Vector2<float> GetScale() const { return scale; }

	void SetName(const std::string& _name) { name = _name; }
	void SetType(const std::string& _type) { type = _type; }
	void SetId(const int& _id) { id = _id; }
	void SetPosition(const Maths::Vector2<float>& _position) { position = _position; }
	void SetLastPosition(const Maths::Vector2<float>& _lastPosition) { lastPosition = _lastPosition; }
	void SetVelocity(const Maths::Vector2<float>& _velocity) { velocity = _velocity; }
	void SetRotation(const float _rotation) { rotation = _rotation; }
	void SetScale(const Maths::Vector2<float>& _scale) { scale = _scale; }

	template<typename T>
	T* CreateComponent();

	template<typename T>
	T* GetComponent();

	std::vector<Component*>& GetComponents();

	void AddComponent(Component* _component);
	void RemoveComponent(Component* _component);

	void Awake() const;
	void Start() const;
	void Update(float _delta_time) const;

	void PreRender() const;
	void Render(sf::RenderWindow* _window) const;
	void OnGUI() const;
	void PostRender() const;
	void OnDebug() const;
	void OnDebugSelected() const;
	void Present() const;

	void OnEnable() const;
	void OnDisable() const;

	void Destroy() const;
	void Finalize() const;

	Scene* GetScene() const { return scene; }
	void SetScene(Scene* _scene) { scene = _scene; }
	const std::vector<Background*>& GetBackgrounds() const { return backgrounds; }
	void SetBackgrounds(std::vector<Background*> _backgrounds) { backgrounds = _backgrounds; }

	void MarkForDeletion() { markedForDeletion = true; }

	bool IsMarkedForDeletion() const { return markedForDeletion;}


private:
	std::string name = "GameObject";
	std::string type = "Default";

	Scene* scene = nullptr;
	std::vector<Background*> backgrounds;

	int id = NULL;
	Maths::Vector2<float> velocity = Maths::Vector2f::Zero;

	Maths::Vector2<float> position = Maths::Vector2f::Zero;
	Maths::Vector2<float> lastPosition = Maths::Vector2f::Zero;

	float rotation = 0.0f;
	Maths::Vector2<float> scale = Maths::Vector2f::One;

	std::vector<Component*> components;

	bool markedForDeletion = false;
};

template<typename T>
T* GameObject::CreateComponent()
{
	T* component = new T();
	component->SetOwner(this);
	components.push_back(component);
	return component;
}

template<typename T>
T* GameObject::GetComponent()
{
	for (Component* component : components)
	{
		T* result = dynamic_cast<T*>(component);
		if (result != nullptr)
			return result;
	}

	return nullptr;
}
