// co_mindustry.cpp : Defines the entry point for the application.
//

#include <Game.h>
#include <python3.10/python.h>

using namespace mindustry;

int main(int argc, char *argv[])
{
	/*Game game;
	game.run_game_loop();*/

	wchar_t *program = Py_DecodeLocale(argv[0], nullptr);
	Py_Initialize();
	PyRun_SimpleString("from time import time\n"
		"print('time is: ',time())\n");
	if (Py_FinalizeEx() < 0)
		std::exit(120);
	
	PyMem_RawFree(program);

	return 0;
}



