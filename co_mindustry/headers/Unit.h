#pragma once
#include <SFML/Graphics.hpp>


enum class Direction
{
	Up = 1,
	Down = -1,
	Left = -2,
	Right = 2
};


namespace game2d
{
class Unit
{
public:
	Unit(const char* image_path, int x, int y);

	sf::Sprite& get_sprite()
	{
		return m_sprite;
	}

	void move(sf::Keyboard::Key key);

	void change_direction(Direction pre, Direction post);
	
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	int m_x, m_y;
	Direction m_direction;
};
};
