#include "engine.hpp"

using namespace gfxcpp;

engine::engine() {
	if (!glfwInit()) {
		exit(1);
	}
}

engine::~engine() { exit(0); }

void engine::exit(const int& error) {
	glfwTerminate();

	switch (error) {
	case 1:
		throw engine_error("GLFW failed to initialize");
	case 2:
		throw engine_error("GLFW window failed to open");
	case 3:
		throw engine_error("GLEW failed to initialize");
	}
}

void engine::init_gl() {
	glewExperimental = true;
	if (GLEW_OK != glewInit()) {
		exit(3);
	}
}

void engine::run(const std::function<void()>& user_run) {
	while (running) {
		glfwPollEvents();

		user_run();
	}
}

void engine::end_loop() { running = false; }

void engine::set_viewport(const int& x, const int& y, const int& width,
						  const int& height) {
	glViewport(x, y, width, height);
}
