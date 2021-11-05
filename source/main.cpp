#include <iostream>

#include "Game.hpp"
#include "Window.hpp"
#include "TestScene.hpp"
#include "Board.hpp"

int main() {
	Engine::Game game = Engine::Game();
	Engine::Window window = Engine::Window("Divitiae", 1280, 720);

	game.setWindow(window);

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
	Board board(game);

	window.setScene(board);

	game.run();

	printf("Program ended\n");
	return 0;
}