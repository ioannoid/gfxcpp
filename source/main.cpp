#include <iostream>

#include "engine.hpp"
#include "mesh_2d.hpp"
#include "shader.hpp"
#include "window.hpp"

using namespace gfxcpp;
using namespace std;

const int WIDTH = 800, HEIGHT = 600;

int main() {
	engine game;
	window window(game, WIDTH, HEIGHT, "Divitiae");

	window.on_close([&] { game.end_loop(); });

	window.make_context_current();
	game.init_gl();

	shader shader(game, "shader.vert", "shader.frag");
	mesh_2d sprite1(game,
					{-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.5f, 0.5f, 0.0f,
					 0.5f, 0.5f, 0.0f, -0.5, 0.5f, 0.0f, -0.5f, -0.5f, 0.0f});
	mesh_2d sprite2(game,
					{0.5f, 0.0f, 0.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f});

	game.set_viewport(0, 0, WIDTH, HEIGHT);

	game.run([&] {
		while (game.is_running()) {
			glClearColor(0.1f, 0.5f, 0.5f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			shader.use_program();
			// sprite1.render();
			sprite2.render();

			window.swap_buffers();
			window.poll_events();
		}

		window.destroy();
	});

	return 0;
}
