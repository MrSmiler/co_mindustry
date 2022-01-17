
#include <SDL.h>
#include <Game.h>
#include <SDL_image.h>
#include <TextureManager.h>
#include <GameObject.h>
#include <Map.h>

#include <cstdint>
#include <iostream>


using namespace game2d;

GameObject* player, *player2;
Map* game_map;
uint32_t counter;

SDL_Renderer* Game::renderer = nullptr;

Game::Game(const char* title, int window_xpos, int window_ypos, int width, int height, bool fullscreen):
	m_window{nullptr},
	m_is_running{false}
{
	if (int err = SDL_Init(SDL_INIT_EVERYTHING) < 0)
		throw "sdl init error";

	int flags = 0;
	if (fullscreen)
		flags |= SDL_WINDOW_FULLSCREEN;

	m_window = SDL_CreateWindow(title, window_xpos, window_ypos, width, height, flags);
	if (m_window == nullptr)
		throw "sdl create window error";

	renderer = SDL_CreateRenderer(m_window, -1, 0);
	if (renderer == nullptr)
		throw "sdl create surface error";

	SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
	m_is_running = true;

	player = new GameObject("assets-raw/sprites/units/beta.png", 0, 0);
	player2 = new GameObject("assets-raw/sprites/units/alpha.png", 100, 100);
	game_map = new Map();
}

void Game::handle_events()
{
	SDL_Event sdl_event;
	SDL_PollEvent(&sdl_event);
	switch (sdl_event.type)
	{
	case SDL_QUIT:
		m_is_running = true;
		break;
	}
}

void Game::update()
{
	player->update();
	player2->update();
	//SDL_UpdateWindowSurface(m_window);
	//SDL_Delay(3000);
}

void Game::render()
{
	SDL_RenderClear(renderer);
	game_map->draw_map();
	player->renderer();
	player2->renderer();
	SDL_RenderPresent(renderer);
}

bool Game::running()
{
	return m_is_running;
}



