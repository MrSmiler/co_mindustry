#pragma once
#include <SFML/Graphics.hpp>

namespace mindustry
{


class RotationAnimComponent
{
public:
	RotationAnimComponent(int rotation, uint32_t duration, sf::Sprite& sprite)
	{
		m_tween.from(0).to(rotation).during(duration);
		m_tween.onStep([&](int x) {
			if (x == 360)
				return true;
			sprite.setRotation(x);
			return false;
		});		
	}

	void animation_step(int step_time)
	{
		m_tween.step(step_time);
	}
private:
	tweeny::tween<int> m_tween;
};


};
