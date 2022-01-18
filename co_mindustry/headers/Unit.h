#pragma once
#include <SFML/Graphics.hpp>

namespace game2d
{
class Unit
{
public:
	Unit(const char* image_path);

	sf::Sprite& get_sprite()
	{
		return m_sprite;
	}
	
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
};
};
