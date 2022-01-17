#include <TextureManager.h>
#include <Game.h>

#include <SDL_image.h>


using namespace game2d;

SDL_Texture* TextureManager::LoadTexture(const char* file_name)
{
	// SDL_Surface* tmp_surface = IMG_Load("assets-raw/sprites/units/beta.png");
	SDL_Surface* tmp_surface = IMG_Load(file_name);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tmp_surface);
	SDL_FreeSurface(tmp_surface);
	return texture;
}

void TextureManager::draw(SDL_Texture* texture, SDL_Rect src_rect, SDL_Rect dst_rect)
{
	SDL_RenderCopy(Game::renderer, texture, &src_rect, &dst_rect);
}
