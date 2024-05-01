#include "Background.h"

void Background::SetPath(const std::string& _path, int _id)
{
    path = _path;
	id = _id;

    if (!texture.loadFromFile(path))
    {
        return;
    }

    if (!image.loadFromFile(path))
    {
        return;
    }

	sprite.setTexture(texture);
}

void Background::SetSize(float _width, float _height)
{
    float scaleX = static_cast<float>(_width) / texture.getSize().x;
    float scaleY = static_cast<float>(_height) / texture.getSize().y;
    sprite.setScale(scaleX, scaleY);
}

void Background::MoveBackground(int _id, float x, float y)
{
	if (id == _id)
	{
		sprite.move(x, y);
	}
}