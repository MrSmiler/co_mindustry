// co_mindustry.cpp : Defines the entry point for the application.
//

#include <Game.h>

using namespace mindustry;

int main(int argc, char *argv[])
{
	Game *game = new Game;
	game->run_game_loop();

	return 0;
}



