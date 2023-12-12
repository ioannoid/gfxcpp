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
	void poll_events();
	void destroy();

    const int& get_width();
    const int& get_height();

	void on_close(const std::function<void()>& on_close_callback);
    void on_resize(const std::function<void(int, int)>& on_resize_callback);

private:
	engine& engine_ref;

	GLFWwindow* glfw_window;
	int width, height;
	std::string title;

	std::function<void()> on_close_callback;
	std::function<void(int, int)> on_resize_callback;

	static void on_close(GLFWwindow* glfw_window);
    static void on_resize(GLFWwindow* glfw_window, int width, int height);
};

} // namespace gfxcpp

#endif // WINDOW_HPP
