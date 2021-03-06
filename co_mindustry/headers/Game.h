#pragma once



#include <systems/DrawSystem.h>
#include <systems/InputSystem.h>

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdint>
#include <entt/entt.hpp>
#include <box2d/box2d.h>


namespace mindustry
{
class Game
{
public:
	Game();
	~Game();

	void run_game_loop();
	void render();
	void update();
private:
	sf::RenderWindow m_window;
	entt::registry m_registry;
	b2World m_b2world;
	mindustry::DrawSystem m_draw_system;
	mindustry::InputSystem m_input_system;
};
};
