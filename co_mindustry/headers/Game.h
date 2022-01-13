
#pragma once

#include <SDL.h>
#include <memory>

namespace game2d
{

class Game
{
public:
	Game(const char* title, int window_xpos, int windows_ypos, int width, int height, bool fullscreen);
	~Game() {
		//Destroy window
		SDL_DestroyWindow(m_window);
		SDL_DestroyRenderer(m_renderer);
		//Quit SDL subsystems
		SDL_Quit();
	};
	
	void handle_events();
	void update();
	void render();
	bool running();

private:
	// bool is_running();

	// TODO: i think since windows is created inside this class this should be unique ptr ?
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	bool m_is_running;
};

};

