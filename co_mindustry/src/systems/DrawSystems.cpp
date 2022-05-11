#include <systems/DrawSystem.h>
#include <components/SpriteComponent.h>
#include <tweeny/tweeny.h>

using namespace mindustry;




void DrawSystem::update(entt::registry& registry, sf::RenderWindow& window)
{	
	auto view = registry.view<SpriteComponent>();
	
	
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

