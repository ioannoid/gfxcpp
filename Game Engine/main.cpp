#include <iostream>

#include "Engine.hpp"
#include "wtf.h"

Engine::Game game;
Engine::Window window;

int main()
{
	game = Engine::Game();
	window = Engine::Window("Divitiae", 1280, 720);

	window.setContext();
	window.onClose([&]() {
		window.close();
		game.close();
	});

	game.initGl();
	game.run();

	/*wtf test = wtf();
	void* test1 = static_cast<void*>(&test);
	wtf* test2 = static_cast<wtf*>(test1);

	test2->asdf();*/

	printf("Ryan Mickey\n");
	system("PAUSE");
	return 0;
}

void Engine::Game::update()
{
	window.update();
}

void Engine::Game::render()
{
	window.render();
}