#include <systems/DrawSystem.h>
#include <components/SpriteComponent.h>
#include <tweeny/tweeny.h>
#include <components/MapComponent.h>

using namespace mindustry;




void DrawSystem::update(entt::registry& registry, sf::RenderWindow& window)
{	
	auto view = registry.view<SpriteComponent>();

	auto map_view = registry.view<GameMap>();
	
	for (auto& entity : map_view)
	{
		GameMap game_map = registry.get<GameMap>(entity);

		int tile_counter = 0;
		for (auto &tile_index: game_map.m_map)
		{
			sf::Texture &texture = game_map.m_resources[tile_index];
			sf::Sprite sprite;
			sprite.setTexture(texture);
			// sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
			int width = window.getSize().x;
			int height = window.getSize().y;
			int i = tile_counter % (width / 32);
			int j = tile_counter / (height / 32);

			sprite.setPosition(i * 32, j * 32);
			tile_counter++;
			window.draw(sprite);
		}

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

