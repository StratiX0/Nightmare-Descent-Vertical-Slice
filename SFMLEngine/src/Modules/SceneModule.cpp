#include "Modules/SceneModule.h"

#include "ModuleManager.h"
#include <iostream>


SceneModule::SceneModule(): Module()
{
	Scene* main_scene = new Scene("DefaultScene");
	Scene* menu_scene = new Scene("Menu_Scene");
	scenes.push_back(menu_scene);
	scenes.push_back(main_scene);
	mainScene = main_scene;
	menuScene = menu_scene;

}

void SceneModule::Start()
{
	Module::Start();

	timeModule = moduleManager->GetModule<TimeModule>();
	windowModule = moduleManager->GetModule<WindowModule>();
}

void SceneModule::Render()
{
	Module::Render();

	for (Scene* scene : scenes)
	{
		scene->Render(windowModule->GetWindow());
	}
}

void SceneModule::Update()
{
	Module::Update();

	if (timeModule == nullptr)
	{
		std::cout << "TimeModule is null." << std::endl;
		return;
	}

	for (Scene* scene : scenes)
	{
		if (scene != nullptr)
		{
			scene->Update(timeModule->GetDeltaTime());
		}
	}
}


void SceneModule::Awake()
{
	Module::Awake();

	for (const Scene* scene : scenes)
	{
		scene->Awake();
	}
}

void SceneModule::Destroy()
{
	Module::Destroy();

	for (const Scene* scene : scenes)
	{
		scene->Destroy();
	}
}

void SceneModule::Finalize()
{
	Module::Finalize();

	for (const Scene* scene : scenes)
	{
		scene->Finalize();
	}
}

void SceneModule::OnDebug()
{
	Module::OnDebug();

	for (const Scene* scene : scenes)
	{
		scene->OnDebug();
	}
}

void SceneModule::OnDebugSelected()
{
	Module::OnDebugSelected();

	for (const Scene* scene : scenes)
	{
		scene->OnDebugSelected();
	}
}

void SceneModule::OnDisable()
{
	Module::OnDisable();

	for (const Scene* scene : scenes)
	{
		scene->OnDisable();
	}
}

void SceneModule::OnEnable()
{
	Module::OnEnable();

	for (const Scene* scene : scenes)
	{
		scene->OnEnable();
	}
}

void SceneModule::OnGUI()
{
	Module::OnGUI();

	for (const Scene* scene : scenes)
	{
		scene->OnGUI();
	}
}

void SceneModule::PostRender()
{
	Module::PostRender();

	for (const Scene* scene : scenes)
	{
		scene->PostRender();
	}
}

void SceneModule::PreRender()
{
	Module::PreRender();

	for (const Scene* scene : scenes)
	{
		scene->PreRender();
	}
}

void SceneModule::Present()
{
	Module::Present();

	for (const Scene* scene : scenes)
	{
		scene->Present();
	}
}

const std::vector<Scene*>& SceneModule::GetScenes() const
{
	return scenes;
}

Scene* SceneModule::GetScene(const std::string& _scene_name) const
{
	for (Scene* scene : scenes)
	{
		if (scene->GetName() == _scene_name)
		{
			return scene;
		}
	}
	return nullptr;
}
