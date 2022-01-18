#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Unit.h>
#include <cstdint>

namespace game2d
{
class Game
{
public:
	Game();
	~Game();

	void run_game_loop();
	void poll_events();
	void render();
	void update();
private:
	sf::RenderWindow m_window;
	sf::Event m_event;
	Unit player;
};
};
