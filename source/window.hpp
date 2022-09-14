#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "engine.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <functional>
#include <string>

namespace gfxcpp {

class window {
public:
	window(engine& engine_ref, const int& width, const int& height,
		   const std::string& title);
	~window();

	void render();
	void update();

	void make_context_current();
	void swap_buffers();

	void on_close(const std::function<void()>& on_close_callback);

private:
	engine& engine_ref;

	GLFWwindow* glfw_window;
	int width, height;
	std::string title;

	std::function<void()> on_close_callback;

	static void on_close(GLFWwindow* glfw_window);
};

} // namespace gfxcpp

#endif // WINDOW_HPP
