#pragma once

#include <SDL.h>

namespace game2d
{

class GameObject
{
public:
	GameObject(const char* texture_sheet, SDL_Renderer* renderer, int x, int y);
	~GameObject();

	void update();
	void renderer();
private:
	uint32_t m_xpos;
	uint32_t m_ypos;

	SDL_Rect m_src_rect, m_dst_rect;
	SDL_Texture* m_texture;
	SDL_Renderer* m_renderer;
};

}
