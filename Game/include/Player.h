#pragma once
#include "Component.h"
#include "InputModule.h"

class Physics;
class AnimatedSpriteComponent;
class Background;
class SquareCollider;

// La classe Player herite de la classe Component et represente un joueur dans le jeu.
class Player : public Component
{
public:

    // Met a jour le joueur.
    void Update(const float _delta_time) override
    {
        // Recupere le GameObject proprietaire de ce composant.
        GameObject* owner = GetOwner();

        // Recupere la position et la vitesse actuelles du GameObject.
        Maths::Vector2<float> position = owner->GetPosition();
        Maths::Vector2<float> velocity = owner->GetVelocity();

        // Recupere la gravite du composant Physics du GameObject.
        gravity = owner->GetComponent<Physics>()->gravity;

        // Deplace legerement le GameObject vers le haut.
        GetOwner()->SetPosition(Maths::Vector2f(position.x, position.y - 0.1f));

        // Si la touche D est enfoncee et que le joueur ne touche pas un obstacle a droite, deplace le monde vers la gauche et met le sprite du joueur en etat de course.
        if (InputModule::GetKey(sf::Keyboard::D) && !owner->GetComponent<Physics>()->collidingRight)
        {
            owner->GetComponent<AnimatedSpriteComponent>()->SetDirection(AnimatedSpriteComponent::MovementDirection::Right);
            owner->GetComponent<AnimatedSpriteComponent>()->SetState(AnimatedSpriteComponent::SpriteState::Running);
            MoveWorld(-speed * _delta_time);
        }

        // Si la touche Q est enfoncee et que le joueur ne touche pas un obstacle a gauche, deplace le monde vers la droite et met le sprite du joueur en etat de course.
        if (InputModule::GetKey(sf::Keyboard::Q) && !owner->GetComponent<Physics>()->collidingLeft)
        {
            owner->GetComponent<AnimatedSpriteComponent>()->SetDirection(AnimatedSpriteComponent::MovementDirection::Left);
            owner->GetComponent<AnimatedSpriteComponent>()->SetState(AnimatedSpriteComponent::SpriteState::Running);
            MoveWorld(speed * _delta_time);
        }

        // Si ni la touche D ni la touche Q ne sont enfoncees, met le sprite du joueur en etat d'inactivite.
        if (!InputModule::GetKey(sf::Keyboard::D) && !InputModule::GetKey(sf::Keyboard::Q) && !InputModule::GetKey(sf::Keyboard::Z))
        {
            owner->GetComponent<AnimatedSpriteComponent>()->SetState(AnimatedSpriteComponent::SpriteState::Idle);
        }

        // Si la touche Z est enfoncee et que le joueur n'est pas deja en train de sauter, fait sauter le joueur.
        if (InputModule::GetKey(sf::Keyboard::Z) && !owner->GetComponent<Physics>()->IsJumping())
        {
            velocity.y = -jumpForce;
            owner->GetComponent<Physics>()->SetJumping(true);
            owner->GetComponent<AnimatedSpriteComponent>()->SetDirection(AnimatedSpriteComponent::MovementDirection::Up);
            owner->GetComponent<AnimatedSpriteComponent>()->SetState(AnimatedSpriteComponent::PlayerSpriteState::Jump);
        }

        // Si le joueur est en train de sauter, ajoute la gravite a la vitesse verticale.
        if (owner->GetComponent<Physics>()->IsJumping())
        {
            velocity.y += gravity.y * _delta_time;
        }

        // Si le joueur est mort, change la couleur du RectangleShapeRenderer en rouge.
        if (owner->GetComponent<Health>()->IsDead() || owner->GetPosition().y > 1080)
        {
            owner->GetComponent<RectangleShapeRenderer>()->SetColor(sf::Color::Red);
			owner->~GameObject();
        }

        // Met a jour la position et la vitesse du GameObject.
        position += velocity * _delta_time;
        owner->SetVelocity(velocity);
        owner->SetPosition(position);
    }

    // Deplace le monde d'une certaine quantite.
    void MoveWorld(float delta)
    {
        // Deplace tous les GameObjects de la scene.
        for (auto& game_object : GetOwner()->GetScene()->GetGameObjects())
        {
            game_object->SetPosition(Maths::Vector2f(game_object->GetPosition().x + delta, game_object->GetPosition().y));
        }
        // Deplace tous les Backgrounds de la scene.
        for (auto& background : GetOwner()->GetScene()->GetBackgrounds())
        {
            background->SetPosition(background->GetPosition().x + delta, background->GetPosition().y);

            // Si un Background sort de l'ecran, le replace de l'autre côte.
            if (background->GetPosition().x <= 0.0f - 1920.0f)
            {
                background->SetPosition(1920.0f, background->GetPosition().y);
            }
            else if (background->GetPosition().x >= 1920.0f)
            {
                background->SetPosition(-1920.0f, background->GetPosition().y);
            }
        }
    }


private:

	// Variables de deplacement du joueur.
    float jumpForce = 800.0f;
    float speed = 700.0f;
    Maths::Vector2<float> gravity;
};

