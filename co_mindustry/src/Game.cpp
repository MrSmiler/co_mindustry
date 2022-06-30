#include <Game.h>
#include <components/InputComponent.h>
#include <components/SpriteComponent.h>
#include <components/MovementComponent.h>
#include <components/AnimationComponent.h>
#include <components/PhysicComponent.h>
#include <components/MapComponent.h>
#include <components/CameraComponent.h>
#include <box2d/box2d.h>


using namespace mindustry;

Game::Game()
	: m_window{ sf::VideoMode(320, 320), "mindustry" },
	m_b2world{ b2Vec2{0, 0} } // there is no gravity in this game
{
	m_window.setFramerateLimit(60);

	auto map = m_registry.create();
	m_registry.emplace<GameMap>(map, GameMap{"assets-raw\\map\\mindustry-spritesheet.png", "assets-raw\\map\\map.json", m_window.getSize().x, m_window.getSize().y});

	auto camera = m_registry.create();
	m_registry.emplace<CameraComponent>(camera, CameraComponent{0, 0, m_window.getSize().x, m_window.getSize().y});

	

	//m_registry.emplace<GameMap>(map, GameMap{"assets-raw\\map\\mindustry-spritesheet.png", "assets-raw\\map\\map.json", m_window.getSize().x, m_window.getSize().y});

	//auto player = m_registry.create();
	//m_registry.emplace<InputComponent>(player, KeysArray{sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::A, sf::Keyboard::D});
	//m_registry.emplace<SpriteComponent>(player, "assets-raw/sprites/units/beta.png");
	//m_registry.emplace<MovementComponent>(player);
	//m_registry.emplace<PhysicComponent>(player, &m_b2world, 200, 200, 56, 54);
}

Game::~Game()
{
}

void Game::run_game_loop()
{
	while (m_window.isOpen())
	{
		m_window.clear(sf::Color::White);
		float timeStep = 1.0f / 60.0f;
		int32 velocityIterations = 6;
		int32 positionIterations = 2;
		m_b2world.Step(timeStep, velocityIterations, positionIterations);
		update();
		render();
	}
}

void Game::render()
{
	m_window.display();
}

void Game::update()
{

	m_input_system.update(m_registry, m_window);

	// draw objects
	m_draw_system.update(m_registry, m_window);
}

