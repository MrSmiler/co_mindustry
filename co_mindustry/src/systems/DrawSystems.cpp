#include <systems/DrawSystem.h>
#include <components/SpriteComponent.h>
#include <tweeny/tweeny.h>
#include <components/MapComponent.h>

using namespace mindustry;




void DrawSystem::update(entt::registry& registry, sf::RenderWindow& window)
{	
	auto view = registry.view<SpriteComponent>();

	auto map_view = registry.view<GameMap>();
	
	// sf::View player_view(sf::FloatRect(0.f, 0.f, 500.f, 500.f));
	// sf::View player_view(sf::Vector2f(400, 400), sf::Vector2f(100, 100));

	for (auto& entity : map_view)
	{
		GameMap game_map = registry.get<GameMap>(entity);

		sf::Texture& texture = game_map.get_tileset_texture();

		// game_map.create_map_vertex()

		sf::RenderStates states;

		states.texture = &texture;

		// window.setView(player_view);

		
		window.draw(game_map.get_vertices(), states);
	}
	
	for (auto& entity : view)
	{
		sf::Sprite sprite = registry.get<SpriteComponent>(entity).get_sprite();
		/*m_tween.onStep([&](int x) {
			if (x == 360)
				return true;

			sprite.setRotation(x);

			return false;
		});		
		m_tween.step(10);*/
		window.draw(sprite);
	}
}

