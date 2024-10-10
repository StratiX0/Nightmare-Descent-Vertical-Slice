#pragma once
#include "Component.h"
#include "Scene.h" 
#include <SFML/Audio.hpp>

class Physics;
class AnimatedSpriteComponent;

// La classe Enemy herite de la classe Component et represente un ennemi dans le jeu.
class Enemy : public Component
{
public:

    sf::SoundBuffer buffer;
    sf::Sound sound;

    Enemy() {
        // Chargez le son à partir d'un fichier
        if (!buffer.loadFromFile("Assets/fireball.wav")) {
            // Gérez l'erreur si le fichier ne peut pas être chargé
        }

        // Créez un objet sf::Sound pour jouer le son
        sound.setBuffer(buffer);
    }


	void Start() override
	{
		name = GetOwner()->GetName();
	}

    // Met a jour l'ennemi.
    void Update(const float _delta_time) override
    {

        // Recupere le GameObject proprietaire de ce composant.
        GameObject* owner = GetOwner();
        // Recupere le GameObject de type "Player".
        GameObject* player = GetOwner()->GetScene()->FindGameObjectType("Player");

        SetPlatformLimits();

        // Recupere la position actuelle du GameObject.
        Maths::Vector2<float> position = owner->GetPosition();

        // Si l'ennemi atteint le bord droit de sa plateforme, il se deplace vers la gauche.
        if (position.x + owner->GetComponent<RectangleShapeRenderer>()->GetSize().x >= rightLimit || owner->GetComponent<Physics>()->collidingRight)
        {
            direction = -1;
            owner->GetComponent<AnimatedSpriteComponent>()->SetDirection(AnimatedSpriteComponent::MovementDirection::Left);
            owner->GetComponent<AnimatedSpriteComponent>()->SetState(AnimatedSpriteComponent::SpriteState::Running);
        }

        // Si l'ennemi atteint le bord gauche de sa plateforme, il se deplace vers la droite.
        else if (position.x <= leftLimit || owner->GetComponent<Physics>()->collidingLeft)
        {
            direction = 1;
            owner->GetComponent<AnimatedSpriteComponent>()->SetDirection(AnimatedSpriteComponent::MovementDirection::Right);
            owner->GetComponent<AnimatedSpriteComponent>()->SetState(AnimatedSpriteComponent::SpriteState::Running);
        }

        // Si l'ennemie est mort, change la couleur du RectangleShapeRenderer en rouge.
        if (owner->GetComponent<Health>()->IsDead())
        {
            owner->GetComponent<RectangleShapeRenderer>()->SetColor(sf::Color::Red);
			owner->~GameObject();
        }

		if (owner->GetName() == "Wizard")
        {
            if (owner->GetComponent<EnemyAttack>()->projectileTimer <= 0.0f && position.x - player->GetPosition().x <= 650) {
                // Jouez le son
                sound.play();
            }
            if (owner->GetComponent<EnemyAttack>()->GetStopToShoot())
            {
                owner->GetComponent<AnimatedSpriteComponent>()->SetState(AnimatedSpriteComponent::SpriteState::Idle);
            }
            else
            {
                // Met a jour la position de l'ennemi.
                position.x += direction * speed * _delta_time;
                owner->SetPosition(position);
            }
		}
        else
        {
            // Met a jour la position de l'ennemi.
            position.x += direction * speed * _delta_time;
            owner->SetPosition(position);
        }
    }

    // Methodes pour definir et obtenir les limites de la plateforme de l'ennemi.
    void SetPlatformLimits()
    {
		SquareCollider* collider = GetOwner()->GetComponent<SquareCollider>();
        for (auto& game_object : GetOwner()->GetScene()->GetGameObjects())
        {
            if (game_object->GetType() == "Object")
            {
                SquareCollider* objectCollider = game_object->GetComponent<SquareCollider>();
                if (SquareCollider::IsColliding(*collider, *objectCollider))
                {
                    SquareCollider* platformCollider = game_object->GetComponent<SquareCollider>();
                    Maths::Vector2f platformPosition = game_object->GetPosition();
                    leftLimit = platformPosition.x;
                    rightLimit = platformPosition.x + platformCollider->GetWidth();
                }
            }
        }
    }

private:

    std::string name;

    // Variables de deplacement de l'ennemi.
    float speed = 200.0f;
    int direction = 1; // 1 pour la droite, -1 pour la gauche.

    // Variables qui stockent les limites de la plateforme de l'ennemi.
    float leftLimit = 0.0f;
    float rightLimit = 0.0f;
};
