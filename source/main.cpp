#include <iostream>

#include "Game.hpp"
#include "Window.hpp"
#include "TestScene.hpp"

int main() {
	Engine::Game game = Engine::Game();
	Engine::Window window = Engine::Window("Doggy Speen", 1280, 720);

	game.setWindow(window);
	window.open();

	window.onClose([&] {
		window.close();
		game.close();
	});
	
	window.onResize([&](int width, int height) {
		window.setViewport(width, height);
	});

	window.setContext();
	game.initGl();

	TestScene testScene(game);

	window.setScene(testScene);

	game.run();

	printf("Program ended\n");
	return 0;
}