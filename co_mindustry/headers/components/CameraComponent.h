#pragma once
#include <SFML/Graphics.hpp>

namespace mindustry
{

class CameraComponent
{
public:
	CameraComponent(uint32_t x, uint32_t y, uint32_t width, uint32_t height):
		_x{x},
		_y{y},
		_width{width},
		_height{height}
	{
	}
	uint32_t x() noexcept { return _x;}
	uint32_t y() noexcept { return _y;}
	uint32_t width() noexcept { return _width;}
	uint32_t height() noexcept { return _height;}

	void set_x(uint32_t x) { _x = x;}
	void set_y(uint32_t y) { _y = y;}
	void set_width(uint32_t width) { _width = width;}
	void set_height(uint32_t height) { _height = height;}

private:
	uint32_t _x, _y, _width, _height;
};

};