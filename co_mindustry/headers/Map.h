#pragma once
#include <SDL.h>
#include <array>

namespace game2d
{

class Map
{
public:
	Map();
	~Map() {};

	using Map2dArray = std::array<std::array<int, 25>, 20>;

	void load_map(Map2dArray map);
	void draw_map();

private:
	SDL_Rect m_src_rect, m_dst_rect;
	SDL_Texture* m_sand;
	SDL_Texture* m_grass;

	Map2dArray m_map;
};

};
