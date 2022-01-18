#include <Game.h>
#include <Unit.h>

using namespace game2d;

Game::Game()
	: m_window{sf::VideoMode(800, 640), "SFML Works"},
	player("assets-raw/sprites/units/flare.png")
{
	m_window.setFramerateLimit(60);
}

Game::~Game()
{
}

void Game::run_game_loop()
{
	while (m_window.isOpen())
	{
		poll_events();
		update();
		render();
	}
}

void Game::poll_events()
{
	while (m_window.pollEvent(m_event))
	{
		switch (m_event.type)
		{
		case sf::Event::Closed:
		{
			m_window.close();
			break;
		}
		case sf::Event::KeyPressed:
		{
			if (m_event.key.code == sf::Keyboard::Escape)
				m_window.close();
			break;
		}
		}
	}
}

void Game::render()
{

	m_window.clear(sf::Color::White);

	// draw objects
	m_window.draw(player.get_sprite());

	m_window.display();
}

void Game::update()
{

}

