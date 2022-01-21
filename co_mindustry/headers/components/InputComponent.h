#pragma once
#include <SFML/Graphics.hpp>

namespace mindustry
{
using KeysArray = std::array<sf::Keyboard::Key, 4>;

class InputComponent
{
public:
	InputComponent(KeysArray input_keys) :
		keys{ input_keys }
	{
	}
	KeysArray keys;
};

};
