#pragma once

#include <SDL.h>

namespace game2d
{

class TextureManager
{
public:
	static SDL_Texture* LoadTexture(const char* file_name);
	static void draw(SDL_Texture* texture, SDL_Rect src_rect, SDL_Rect dst_rect);
};

};
