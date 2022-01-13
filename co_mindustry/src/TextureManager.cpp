#include <TextureManager.h>
#include <SDL_image.h>

using namespace game2d;

SDL_Texture* TextureManager::LoadTexture(const char* file_name, SDL_Renderer* renderer)
{
	// SDL_Surface* tmp_surface = IMG_Load("assets-raw/sprites/units/beta.png");
	SDL_Surface* tmp_surface = IMG_Load(file_name);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tmp_surface);
	SDL_FreeSurface(tmp_surface);
	return texture;
}
