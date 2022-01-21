#include <Game.h>
#include <components/InputComponent.h>
#include <components/SpriteComponent.h>

using namespace mindustry;


Game::Game()
	: m_window{sf::VideoMode(800, 640), "mindustry"}
{
	m_window.setFramerateLimit(60);
	auto player = m_registry.create();
	m_registry.emplace<InputComponent>(player, KeysArray{sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::A, sf::Keyboard::D});
	m_registry.emplace<SpriteComponent>(player, "assets-raw/sprites/units/beta.png");
}

Game::~Game()
{
}

void Game::run_game_loop()
{
	while (m_window.isOpen())
	{
		update();
		render();
	}
}

void Game::render()
{

	m_window.clear(sf::Color::White);
	m_input_system.update(m_registry, m_window);
	// draw objects
	m_draw_system.update(m_registry, m_window);

	m_window.display();
}

void Game::update()
{

}

