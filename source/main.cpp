#include <iostream>

#include "Game.hpp"
#include "Window.hpp"
#include "TestScene.hpp"

int main()
{
	Engine::Game game = Engine::Game();
	Engine::Window window = Engine::Window("Divitiae", 1280, 720);

	game.onRender([&] {
		window.render();
	});

	game.onUpdate([&] {
		window.update();
	});

	window.onClose([&] {
		window.close();
		game.close();
	});
	
	window.onResize([&](int width, int height) {
		window.setViewport(width, height);
	});

	window.open();

	window.setContext();
	game.initGl();

	TestScene testScene;

	window.setScene(testScene);

	game.run();

	printf("Program ended\n");
	return 0;
}