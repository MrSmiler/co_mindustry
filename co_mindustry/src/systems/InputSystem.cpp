
#include <systems/InputSystem.h>
#include <components/InputComponent.h>
#include <components/SpriteComponent.h>

using namespace mindustry;

void InputSystem::update(entt::registry& registry, sf::RenderWindow& window)
{
	auto view = registry.view<InputComponent, SpriteComponent>();
	
	for (auto& entity : view)
	{
		InputComponent& input = registry.get<InputComponent>(entity);
		sf::Sprite& sprite = registry.get<SpriteComponent>(entity).get_sprite();
		int move_x = 0, move_y = 0;

		for (auto& key : input.keys)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();

			if (!sf::Keyboard::isKeyPressed(key))
				continue;

			switch (key)
			{
			case sf::Keyboard::W:
				move_y = -10;
				break;
			case sf::Keyboard::S:
				move_y = +10;
				break;
			case sf::Keyboard::A:
				move_x = -10;
				break;
			case sf::Keyboard::D:
				move_x = +10;
				break;
			}
			sprite.move(move_x, move_y);
		}
			
	}
}
