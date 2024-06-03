#include "Engine.h"
#include "SceneModule.h"
#include "Scenes/DefaultScene.h"
#include "Scenes/MenuScene.h"

int main()
{
	const Engine* engine = Engine::GetInstance();

	engine->Init();

	SceneModule* scene_module = engine->GetModuleManager()->GetModule<SceneModule>();
	scene_module->SetScene<MenuScene>();

	engine->Run();


    while (scene_module->GetScene("MainMenuScene"))
    {
        sf::Vector2i mouse = sf::Mouse::getPosition();
        printf("oui!!!!!!!!\n");

        if (mouse.x >= 818 && mouse.x <= 1124) {
            if (mouse.y >= 514 && mouse.y <= 620) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    printf("oui");
                    scene_module->SetScene<DefaultScene>();
                }
            }
        }
    }

	return 0;
}
