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
#include "Components/PlayerAttack.h"
#include "Components/EnemyAttack.h"
#include "Components/Projectile.h"

// La classe Scene represente une scene dans votre jeu. Une scene contient un ensemble de GameObjects.
class Scene
{
public:

    // Constructeur et destructeur de la classe Scene.
    explicit Scene(const std::string& _name);
    virtual ~Scene() = default;

    // Methodes pour reveiller, demarrer, mettre a jour, pre-rendre, rendre, post-rendre, presenter, activer, desactiver, detruire et finaliser la scene.
    void Awake() const;
    void Start() const;
    void Update(const float _delta_time);
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

    // Methode pour obtenir le nom de la scene.
    const std::string& GetName() const;

    // Methodes pour creer un GameObject dans la scene, creer un GameObject, creer des arriere-plans, detruire un GameObject, trouver un GameObject par son nom ou son type, et obtenir tous les GameObjects.
    GameObject* CreateInGameObject(const std::string& _name, const std::string& _type, Maths::Vector2f _position, Maths::Vector2f _size, float _mass, const sf::Color _color);
    GameObject* CreateGameObject(const std::string& _name, const std::string& _type, const int id);
    GameObject* CreateProjectile(const std::string& _name, const std::string& _type, Maths::Vector2f _position, Maths::Vector2f _size, const float _damage, const float _speed, const sf::Color _color);
    void CreateBackgrounds(const std::string& _path);
    std::vector<Background*> GetBackgrounds() const { return backgrounds; }
    void SetBackgroundSize(Background* background, float _width, float _height);
    void DestroyGameObject(const GameObject* _game_object);
    GameObject* FindGameObject(const std::string& _name) const;
    GameObject* FindGameObjectType(const std::string& _type) const;
    const std::vector<GameObject*>& GetGameObjects() const;

private:

    // Variables pour stocker le nom de la scene, les GameObjects de la scene, l'ID du prochain GameObject a creer, et les arriere-plans de la scene.
    std::string name;
    std::vector<GameObject*> gameObjects;
    int id = 0;
    std::vector<Background*> backgrounds;
};
