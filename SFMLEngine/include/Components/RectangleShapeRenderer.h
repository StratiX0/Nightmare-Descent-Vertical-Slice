#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

#include "ARendererComponent.h"
#include <functional>

class RectangleShapeRenderer : public ARendererComponent
{
public:
	RectangleShapeRenderer();
	~RectangleShapeRenderer() override;

	void SetColor(const sf::Color& _color) { color = _color; }

	void Render(sf::RenderWindow* _window) override;
	void OnDebug() override;
	void SetOnClick(std::function<void()> onClickFunc);

private:
	sf::Color color = sf::Color::White;
	std::function<void()> onClick;
	sf::RectangleShape* shape = nullptr;
};
