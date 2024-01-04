#include "window.hpp"
#include <GLFW/glfw3.h>

using namespace gfxcpp;
using namespace std;

window::window(class engine& engine_ref, const int& width, const int& height,
			   const string& title)
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
	glfwSetWindowSizeCallback(glfw_window, on_resize);
    glfwSetKeyCallback(glfw_window, on_key);
}

window::~window() {}

void window::make_context_current() {
	glfwMakeContextCurrent(nullptr);
	glfwMakeContextCurrent(glfw_window);
}

void window::swap_buffers() { glfwSwapBuffers(glfw_window); }

void window::poll_events() { glfwPollEvents(); }

void window::destroy() { glfwDestroyWindow(glfw_window); }

const int& window::get_width() { return width; }

const int& window::get_height() { return height; }

void window::on_close(const function<void()>& on_close_callback) {
	this->on_close_callback = on_close_callback;
}

void window::on_resize(const function<void(int, int)>& on_resize_callback) {
	this->on_resize_callback = on_resize_callback;
}

void window::on_key(const function<void(int, int, int, int)>& on_key_callback) {
    this->on_key_callback = on_key_callback;
}

void window::on_close(GLFWwindow* glfw_window) {
	window* self = static_cast<window*>(glfwGetWindowUserPointer(glfw_window));
	self->on_close_callback();
}

void window::on_resize(GLFWwindow* glfw_window, int width, int height) {
	window* self = static_cast<window*>(glfwGetWindowUserPointer(glfw_window));
	self->width = width;
	self->height = height;
	self->on_resize_callback(self->width, self->height);
}

void window::on_key(GLFWwindow* glfw_window, int key, int scancode, int action, int mods) {
    window* self = static_cast<window*>(glfwGetWindowUserPointer(glfw_window));
    self->on_key_callback(key, scancode, action, mods);
}
