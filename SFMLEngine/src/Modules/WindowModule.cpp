#include "Modules/WindowModule.h"

#include <iostream>
#include <SFML/Window/Event.hpp>

#include "Engine.h"

void WindowModule::Awake()
{
	Module::Awake();

	window = new sf::RenderWindow(sf::VideoMode(1600, 900), "Nightmare Descent");

	// Chargement du logo
	sf::Image icon;
	if (!icon.loadFromFile("Assets/logo-nightmare-descent.png"))
	{
		//Erreur
	}

	// Mettre l'icone
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void WindowModule::PreRender()
{
	Module::PreRender();

	window->clear(sf::Color::Black);
}

void WindowModule::Present()
{
	Module::Present();

	window->display();
}

void WindowModule::Destroy()
{
	Module::Destroy();

	window->close();
}
