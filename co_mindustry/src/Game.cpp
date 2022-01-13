
#include <SDL.h>
#include <Game.h>
#include <SDL_image.h>
#include <TextureManager.h>
#include <GameObject.h>

#include <cstdint>
#include <iostream>


using namespace game2d;

GameObject* player, *player2;
uint32_t counter;

Game::Game(const char* title, int window_xpos, int window_ypos, int width, int height, bool fullscreen):
	m_window{nullptr},
	m_renderer{nullptr},
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

	m_renderer = SDL_CreateRenderer(m_window, -1, 0);
	if (m_renderer == nullptr)
		throw "sdl create surface error";

	SDL_SetRenderDrawColor(m_renderer, 0xff, 0xff, 0xff, 0xff);
	m_is_running = true;

	player = new GameObject("assets-raw/sprites/units/beta.png", m_renderer, 0, 0);
	player2 = new GameObject("assets-raw/sprites/units/alpha.png", m_renderer, 100, 100);
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
	SDL_RenderClear(m_renderer);
	player->renderer();
	player2->renderer();
	SDL_RenderPresent(m_renderer);
}

bool Game::running()
{
	return m_is_running;
}



