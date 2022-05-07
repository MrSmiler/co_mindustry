
#include <systems/InputSystem.h>
#include <components/InputComponent.h>
#include <components/SpriteComponent.h>
#include <components/MovementComponent.h>

using namespace mindustry;

void InputSystem::update(entt::registry& registry, sf::RenderWindow& window)
{
	auto view = registry.view<InputComponent, MovementComponent, SpriteComponent>();
	using Direction = MovementComponent::Direction;
	
	for (auto& entity : view)
	{
		InputComponent& input = registry.get<InputComponent>(entity);
		MovementComponent& movement = registry.get<MovementComponent>(entity);
		sf::Sprite& sprite = registry.get<SpriteComponent>(entity).get_sprite();

		int move_x = 0, move_y = 0;

		for (auto& key : input.keys)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();

			if (!sf::Keyboard::isKeyPressed(key))
				continue;

			int angle = 0; 
			switch (key)
			{
			case sf::Keyboard::W:
			{
				angle = movement.get_rotation_angle(Direction::Up);
				move_y = -10;
				break;
			}
			case sf::Keyboard::S:
			{
				angle = movement.get_rotation_angle(Direction::Down);
				move_y = +10;
				break;
			}
			case sf::Keyboard::A:
			{
				angle = movement.get_rotation_angle(Direction::Left);
				move_x = -5;
				break;
			}
			case sf::Keyboard::D:
			{
				angle = movement.get_rotation_angle(Direction::Right);
				move_x = +5;
				break;
			}
			}
			sprite.move(move_x, move_y);
			sprite.setRotation(angle);
		}
			
	}
}
