
#include <iostream>
#include <systems/InputSystem.h>
#include <components/InputComponent.h>
#include <components/SpriteComponent.h>
#include <components/MovementComponent.h>
#include <components/PhysicComponent.h>

using namespace mindustry;

void InputSystem::update(entt::registry& registry, sf::RenderWindow& window)
{
	auto view = registry.view<InputComponent, MovementComponent, SpriteComponent, PhysicComponent>();
	using Direction = MovementComponent::Direction;
	
	for (auto& entity : view)
	{
		InputComponent& input = registry.get<InputComponent>(entity);
		MovementComponent& movement = registry.get<MovementComponent>(entity);
		sf::Sprite& sprite = registry.get<SpriteComponent>(entity).get_sprite();
		PhysicComponent& physic = registry.get<PhysicComponent>(entity);
		b2Body* b2body = physic.get_body();

		b2Vec2 vel = b2body->GetLinearVelocity();

		vel.x = vel.y = 0;
		int angle = 0; 
		// angle = movement.get_rotation_angle(Direction::Up);
		for (auto& key : input.keys)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();

			if (!sf::Keyboard::isKeyPressed(key))
				continue;
			const float speed = (float)2;
			switch (key)
			{
				case sf::Keyboard::W:
				{
					// move_y = -5;
					vel.y = -speed;
					break;
				}
				case sf::Keyboard::S:
				{
					angle = movement.get_rotation_angle(Direction::Down);
					// move_y = +5;
					vel.y = speed;
					break;
				}
				case sf::Keyboard::A:
				{
					angle = movement.get_rotation_angle(Direction::Left);
					// move_x = -5;
					vel.x = -speed;
					break;
				}
				case sf::Keyboard::D:
				{
					angle = movement.get_rotation_angle(Direction::Right);
					// move_x = +5;
					vel.x = speed;
					break;
				}
			}
			
		}

		b2body->SetLinearVelocity(vel);

		const b2Vec2 pos = b2body->GetPosition();

		sprite.setPosition(pos.x*physic.get_scale_factor(),
						   pos.y*physic.get_scale_factor());

		sprite.setRotation(angle);
	}
}
