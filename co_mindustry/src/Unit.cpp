
#include <unit.h>

using namespace game2d;


void setOriginAndReadjust(sf::Transformable &object, const sf::Vector2f &newOrigin)
{
        auto offset = newOrigin - object.getOrigin();
        object.setOrigin(newOrigin);
        object.move(offset);
}

Unit::Unit(const char* image_path, int x, int y)
	: m_x{x},
	m_y{y}
{
	//"C:\Users\Mr.Smiler\source\repos\co_mindustry\co_mindustry\assets-raw\sprites\units\flare.png"
	
	if (!m_texture.loadFromFile(image_path))
	{
		throw "can not load from file";
	}
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_x, m_y);
	// auto xx = m_sprite.getLocalBounds();
	setOriginAndReadjust(m_sprite, {m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2});
	m_sprite.setRotation(90);

}
void Unit::move(sf::Keyboard::Key key)
{
	int x = 0, y = 0;
	switch (key)
	{
	case sf::Keyboard::W:
		y = -10;
		break;
	case sf::Keyboard::S:
	{
		y = 10;
		break;
	}
	case sf::Keyboard::A:
		x = -10;
		break;
	case sf::Keyboard::D:
		x = 10;
		break;
	}
	m_sprite.move(x, y);
	// m_sprite.setPosition(sf::Vector2f(m_x, m_y));
}

void Unit::change_direction(Direction pre, Direction post)
{
	switch (pre)
	{
	case Direction::Up:
		break;
	case Direction::Down:
		break;
	case Direction::Left:
		break;
	case Direction::Right:
		break;
	default:
		break;
	}
}

