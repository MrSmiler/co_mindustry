#pragma once
#include <SFML/Graphics.hpp>

namespace mindustry
{
class SpriteComponent
{
public:
	SpriteComponent(const char* file_name)
	{
		if (!m_texture.loadFromFile(file_name))
		{
			throw "wasn't able to load the texture from file";
		}
		m_sprite.setTexture(m_texture);
		m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);
		m_sprite.setPosition(200, 200);
	}

	sf::Sprite& get_sprite()
	{
		return m_sprite;
	}

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
};
};
