#pragma once

#include <SDL.h>

namespace game2d
{

class TextureManager
{
public:
	static SDL_Texture* LoadTexture(const char* file_name, SDL_Renderer* renderer);
};

};
