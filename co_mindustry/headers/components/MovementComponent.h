#pragma once

namespace mindustry
{

class MovementComponent
{
public:
	MovementComponent()
		: m_current_direction{Direction::Up}
	{
	}

	enum class Direction
	{
		Up = 0, 
		Right,
		Down,
		Left,
	};

	int get_rotation_angle(Direction new_direction)
	{
		return static_cast<int>(new_direction) * 90;
	}
	
private:
	Direction m_current_direction;
};

};

