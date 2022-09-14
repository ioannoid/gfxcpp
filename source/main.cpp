#include <iostream>

#include "engine.hpp"
#include "window.hpp"

using namespace gfxcpp;

const int WIDTH = 800, HEIGHT = 600;

int main() {
	engine game;
	window window(game, WIDTH, HEIGHT, "Divitiae");

	window.on_close([&game] { game.end_loop(); });

	window.make_context_current();
	game.init_gl();
	game.set_viewport(0, 0, WIDTH, HEIGHT);

	game.run([&window] {
		glClearColor(0.1f, 0.5f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		window.swap_buffers();
	});

	return 0;
}
