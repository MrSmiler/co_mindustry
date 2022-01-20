#include <Game.h>
#include <Unit.h>

using namespace game2d;


Game::Game()
	: m_window{sf::VideoMode(800, 640), "mindustry"},
	player("assets-raw/sprites/units/beta.png", 0, 0)
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

			switch (m_event.key.code)
			{
			case sf::Keyboard::Escape:
				m_window.close();
				break;
			case sf::Keyboard::W :
			case sf::Keyboard::S :
			case sf::Keyboard::A :
			case sf::Keyboard::D :
				player.move(m_event.key.code);
				break;
			}
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

