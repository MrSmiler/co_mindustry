#pragma once

#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>

namespace mindustry
{
class InputSystem
{
public:
	void update(entt::registry& registry, sf::RenderWindow& window);
};
};