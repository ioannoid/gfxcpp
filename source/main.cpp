#include <iostream>

#include "engine.hpp"
#include "shader.hpp"
#include "window.hpp"

using namespace gfxcpp;

const int WIDTH = 800, HEIGHT = 600;

int main() {
	engine game;
	window window(game, WIDTH, HEIGHT, "Divitiae");
	// shader shader(game, "shader.vert", "shader.frag");

	window.on_close([&] { game.end_loop(); });

	window.make_context_current();
	game.init_gl();
	game.set_viewport(0, 0, WIDTH, HEIGHT);

	game.run([&] {
		while (game.is_running()) {
			glClearColor(0.1f, 0.5f, 0.5f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			window.swap_buffers();
			window.poll_events();
		}
		window.destroy();
	});

	return 0;
}
