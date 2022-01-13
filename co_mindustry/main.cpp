// co_mindustry.cpp : Defines the entry point for the application.
//

#include <iostream>

#define SDL_MAIN_HANDLED
#include <SDL.h> 
#include <Game.h>

using namespace game2d;

int main()
{
	const uint32_t FPS = 60;
	const uint32_t frame_delay = 1000 / 60;

	uint32_t frame_start;
	uint32_t frame_time;

	try {
		Game game{ "first game", 100, 100, 600, 500, false };
		
		while (game.running())
		{
			frame_start = SDL_GetTicks();
			game.handle_events();
			game.update();
			game.render();
			frame_time = SDL_GetTicks() - frame_start;

			if (frame_delay > frame_time)
				SDL_Delay(frame_delay - frame_time);
		}
	}
	catch (...)
	{
		std::cout << "errr happennd" << std::endl;
	}

	return 0;
}



