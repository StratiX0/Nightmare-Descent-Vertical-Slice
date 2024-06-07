#pragma once
#include "Component.h"
#include "InputModule.h"
#include "../Scenes/DefeatScene.h"
#include "Engine.h"
#include "Modules/SceneModule.h"
//#include <SFML/Audio.hpp>

class Physics;
class AnimatedSpriteComponent;
class Background;
class SquareCollider;

// La classe Player herite de la classe Component et represente un joueur dans le jeu.
class Player : public Component
{
public:
    //sf::SoundBuffer bufferJump;
    //sf::SoundBuffer bufferStep;
    //sf::SoundBuffer bufferAttack;
    //sf::Sound soundJump;
    //sf::Sound soundStep;
    //sf::Sound soundAttack;
    

    //Player()
    //{
        // Chargez les sons à partir des fichiers
        //if (!bufferJump.loadFromFile("Assets/jumping.ogg")) {
            // Gérez l'erreur si le fichier ne peut pas être chargé
        //}
        //if (!bufferStep.loadFromFile("Assets/running.ogg")) {
            // Gérez l'erreur si le fichier ne peut pas être chargé
        //}
        //if (!bufferAttack.loadFromFile("Assets/attack.ogg")) {
        // Gérez l'erreur si le fichier ne peut pas être chargé
    //}

        // Créez les objets sf::Sound pour jouer les sons
        //soundJump.setBuffer(bufferJump);
        //soundStep.setBuffer(bufferStep);
        //soundAttack.setBuffer(bufferAttack);
    //}

    // Met a jour le joueur.
    void Update(const float _delta_time) override
    {
        // Recupere le GameObject proprietaire de ce composant.
        GameObject* owner = GetOwner();
        Engine* engine = Engine::GetInstance();
        SceneModule* scene_module = engine->GetModuleManager()->GetModule<SceneModule>();

        // Recupere la position et la vitesse actuelles du GameObject.
        Maths::Vector2<float> position = owner->GetPosition();
        Maths::Vector2<float> velocity = owner->GetVelocity();

        // Recupere la gravite du composant Physics du GameObject.
        gravity = owner->GetComponent<Physics>()->gravity;

        // Deplace legerement le GameObject vers le haut.
        GetOwner()->SetPosition(Maths::Vector2f(position.x, position.y - 0.1f));

        // Si la touche D est enfoncee et que le joueur ne touche pas un obstacle a droite, deplace le monde vers la gauche et met le sprite du joueur en etat de course.
        if (InputModule::GetKey(sf::Keyboard::D) && !owner->GetComponent<Physics>()->collidingRight && !owner->GetComponent<Health>()->IsDead() && !owner->GetComponent<Physics>()->IsAttacking())
        {
            owner->GetComponent<AnimatedSpriteComponent>()->SetDirection(AnimatedSpriteComponent::MovementDirection::Right);
            if (!owner->GetComponent<Physics>()->IsJumping())
            {
                owner->GetComponent<AnimatedSpriteComponent>()->SetState(AnimatedSpriteComponent::SpriteState::Running);
            }
            MoveWorld(-speed * _delta_time);
            //soundStep.play();
        }

        // Si la touche Q est enfoncee et que le joueur ne touche pas un obstacle a gauche, deplace le monde vers la droite et met le sprite du joueur en etat de course.
        if (InputModule::GetKey(sf::Keyboard::Q) && !owner->GetComponent<Physics>()->collidingLeft && !owner->GetComponent<Health>()->IsDead() && !owner->GetComponent<Physics>()->IsAttacking())
        {
            owner->GetComponent<AnimatedSpriteComponent>()->SetDirection(AnimatedSpriteComponent::MovementDirection::Left);
            if (!owner->GetComponent<Physics>()->IsJumping())
            {
                owner->GetComponent<AnimatedSpriteComponent>()->SetState(AnimatedSpriteComponent::SpriteState::Running);
            }
            MoveWorld(speed * _delta_time);
            //soundStep.play();
        }

        // Si ni la touche D, ni la touche Q, ni la touche Z ne sont enfoncees, met le sprite du joueur en etat d'inactivite.
        if (!InputModule::GetKey(sf::Keyboard::D) && !InputModule::GetKey(sf::Keyboard::Q) && !InputModule::GetKey(sf::Keyboard::Z))
        {
            owner->GetComponent<AnimatedSpriteComponent>()->SetState(AnimatedSpriteComponent::SpriteState::Idle);
        }

        //-------------------------------------------COMMANDE POUR L'ATTAQUE----------------------------------------------//
        // Si le bouton de souris est enfoncee et que le joueur n'est pas deja en train d'attaquer, fait attaquer le joueur.
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !owner->GetComponent<Physics>()->IsAttacking() && !owner->GetComponent<Health>()->IsDead())
        {
            owner->GetComponent<Physics>()->SetAttack(true);
            //soundAttack.play();
        }
        // Si le joueur est en train d'attaquer, selon la direction fait défiler le monde et active l'état d'attaque.
        if (owner->GetComponent<Physics>()->IsAttacking())
        {
            owner->GetComponent<AnimatedSpriteComponent>()->SetState(AnimatedSpriteComponent::SpriteState::Attack);

            if (owner->GetComponent<AnimatedSpriteComponent>()->GetCurrentFrame() < 8 && owner->GetComponent<AnimatedSpriteComponent>()->GetCurrentFrame() > 4) {
                if (owner->GetComponent<AnimatedSpriteComponent>()->GetDirection() == 1 && !owner->GetComponent<Physics>()->collidingRight) {
                    MoveWorld(-speed * _delta_time);
                }
                else if (owner->GetComponent<AnimatedSpriteComponent>()->GetDirection() == 0 && !owner->GetComponent<Physics>()->collidingLeft) {
                    MoveWorld(speed * _delta_time);
                }
            }

            if (owner->GetComponent<AnimatedSpriteComponent>()->GetCurrentFrame() == 12) {
                owner->GetComponent<Physics>()->SetAttack(false);
            }
        }
        //--------------------------------------------------------------------------------------------------------------//
        
        // Si la touche Z est enfoncee et que le joueur n'est pas deja en train de sauter, fait sauter le joueur.
        if (InputModule::GetKey(sf::Keyboard::Z) && !owner->GetComponent<Physics>()->IsJumping() && !owner->GetComponent<Health>()->IsDead() && !owner->GetComponent<Physics>()->IsAttacking())
        {
            velocity.y = -jumpForce;
            owner->GetComponent<Physics>()->SetJumping(true);
            owner->GetComponent<AnimatedSpriteComponent>()->SetDirection(AnimatedSpriteComponent::MovementDirection::Up);
            //soundJump.play();
        }
       
        // Si le joueur est en train de sauter, ajoute la gravite a la vitesse verticale et active l'état de saut.
        if (owner->GetComponent<Physics>()->IsJumping())
        {
            velocity.y += gravity.y * _delta_time;
            owner->GetComponent<AnimatedSpriteComponent>()->SetState(AnimatedSpriteComponent::SpriteState::Jump);
        }

        // Si le joueur est mort, met l'animation de mort, attend qu'elle se termine et change la couleur du RectangleShapeRenderer en rouge. Puis affiche la scene de défaite.
        if (owner->GetComponent<Health>()->IsDead() || owner->GetPosition().y > 1080)
        {
            owner->GetComponent<AnimatedSpriteComponent>()->SetFrameTime(0.2f);
            owner->GetComponent<AnimatedSpriteComponent>()->SetState(AnimatedSpriteComponent::SpriteState::Death);

            if (owner->GetComponent<AnimatedSpriteComponent>()->GetCurrentFrame() == 14) {
                // détruit le gameobject et change de scène
                owner->~GameObject();

                scene_module->SetScene<DefeatScene>();
            }
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

