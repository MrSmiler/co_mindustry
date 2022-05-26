#pragma once
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

namespace mindustry 
{
class PhysicComponent
{
public:
	PhysicComponent(b2World* world, int pos_x, int pos_y, int width, int height):
		m_b2world {world},
		m_b2body {nullptr}
	{
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		float px = pos_x / 100;
		float py = pos_y / 100;

		bodyDef.position.Set(px, py);
		m_b2body = world->CreateBody(&bodyDef);

		float pw = (float)width / 200;
		float ph = (float)height / 200;
		b2PolygonShape dynamicBox;

		dynamicBox.SetAsBox(pw, ph);

		b2FixtureDef fixtureDef;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = 1.0f;
		// fixtureDef.friction = 0.3f;

		m_b2body->CreateFixture(&fixtureDef);
	}
	~PhysicComponent()
	{
		// TODO: should we destroy fixture from the body

		m_b2world->DestroyBody(m_b2body);
	}
	int get_scale_factor()
	{
		return scale_factor;
	}

	b2Body* get_body()
	{
		return m_b2body;
	}

private:
	static const int scale_factor = 100;
	b2World* m_b2world;
	b2Body* m_b2body;

};
}
