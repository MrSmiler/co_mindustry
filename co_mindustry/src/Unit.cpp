
#include <unit.h>

using namespace game2d;

Unit::Unit(const char* image_path)
{
	//"C:\Users\Mr.Smiler\source\repos\co_mindustry\co_mindustry\assets-raw\sprites\units\flare.png"
	
	if (!m_texture.loadFromFile(image_path))
	{
		throw "can not load from file";
	}
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(100, 100);
}
