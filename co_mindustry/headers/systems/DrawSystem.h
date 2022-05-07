#pragma once
#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>
#include <tweeny.h>

namespace mindustry
{

class DrawSystem
{
public:
	DrawSystem()
	{
		// m_tween = tweeny::from(0).to(360).during(1000);
	}
	void update(entt::registry& registry, sf::RenderWindow& window);
	// tweeny::tween<int> m_tween;
};
};