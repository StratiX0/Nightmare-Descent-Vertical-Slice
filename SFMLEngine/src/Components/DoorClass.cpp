#include "Components/DoorClass.h"
#include "Physics.h"

// Constructeur par defaut de la classe Door.
DoorGameObject::DoorGameObject()
{
}

// Destructeur de la classe Door.
DoorGameObject::~DoorGameObject()
{
}

// Methode pour verifier si la porte est en collision avec un ennemi.
void DoorGameObject::IsColliding()
{

    // Recupere le GameObject proprietaire de ce composant (la porte).
    GameObject* Door = GetOwner();

    // Recupere le SquareCollider de la porte.
    SquareCollider* DoorCollider = Door->GetComponent<SquareCollider>();

    // Parcourt tous les GameObjects dans la scene.
    for (auto& gameObject : Door->GetScene()->GetGameObjects())
    {

        // Si le GameObject actuel est un ennemi
        if (gameObject->GetType() == "Player")
        {
            // Recupere le SquareCollider de l'ennemi.
            SquareCollider* playerCollider = gameObject->GetComponent<SquareCollider>();

            // Si la porte est en collision avec le player met la valeur de CollidePlayer sur true.
            if (SquareCollider::IsColliding(*DoorCollider, *playerCollider))
            {
                Door->GetComponent<Physics>()->SetDoorIsColliding(true);
                Door->GetComponent<Physics>()->SetDoorIsReached(true);
            }
            else if(!SquareCollider::IsColliding(*DoorCollider, *playerCollider)) {
                Door->GetComponent<Physics>()->SetDoorIsColliding(false);
            }
        }
    }
}

// Methode pour mettre à jour la Door.
void DoorGameObject::Update(float _delta_time)
{

    // Verifie si la porte est en collision avec un ennemi.
    IsColliding();
}