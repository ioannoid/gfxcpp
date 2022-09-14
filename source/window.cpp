#include "window.hpp"
#include <GLFW/glfw3.h>

using namespace gfxcpp;

window::window(class engine& engine_ref, const int& width, const int& height,
			   const std::string& title)
	: engine_ref(engine_ref), title(title) {

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	glfw_window =
		glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	if (!glfw_window) {
		engine_ref.exit(2);
	}

	glfwGetFramebufferSize(glfw_window, &this->width, &this->height);

	glfwSetWindowUserPointer(glfw_window, this);

	glfwSetWindowCloseCallback(glfw_window, on_close);
}

window::~window() {}

void window::make_context_current() {
	glfwMakeContextCurrent(nullptr);
	glfwMakeContextCurrent(glfw_window);
}

void window::swap_buffers() { glfwSwapBuffers(glfw_window); }

void window::on_close(const std::function<void()>& on_close_callback) {
	this->on_close_callback = on_close_callback;
}

void window::on_close(GLFWwindow* glfw_window) {
	window* self = static_cast<window*>(glfwGetWindowUserPointer(glfw_window));
	self->on_close_callback();
}
