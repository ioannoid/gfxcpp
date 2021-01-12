#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <exception>
#include <iostream>
#include <vector>
#include <string>
#include <functional>
// #include <thread>
// #include <atomic>

namespace Engine
{
	class Game
	{
	public:
		Game();

		void initGl();
		void run();
		void onUpdate(const std::function<void()>& update);
		void onRender(const std::function<void()>& render);
		void clean();

		bool isRunning();
		void close();

	private:
		bool running = false;

		std::function<void()> update;
		std::function<void()> render;
	};

	// ---------- Game Class ---------- 

	Game::Game() {
		if (!glfwInit()) {
			fprintf(stderr, "GLFW failed to initialize\n");
			throw std::runtime_error("GLFW failed to initialize");
		}

		glfwWindowHint(GLFW_SAMPLES, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);

		running = true;
	}

	void Game::initGl() {
		glewExperimental = true;
		if (glewInit() != GLEW_OK) {
			fprintf(stderr, "GLEW failed to initialize\n");
			glfwTerminate();
			throw std::runtime_error("GLEW failed to initialize");
		}
	}

	void Game::clean() {
		glfwTerminate();
	}

	void Game::run() {
		// std::thread thread(&Engine::Game::render, this);
		// thread.detach();
		while(running) {
			render();
			update();

		}

		clean();
	}

	void Game::onUpdate(const std::function<void()>& update) {
		this->update = update;
	}

	void Game::onRender(const std::function<void()>& render) {
		this->render = render;
	}

	bool Game::isRunning() {
		return running;
	}

	void Game::close() {
		running = false;
	}

	class Window
	{
	public:
		Window();
		Window(const std::string& title, const int& width, const int& height);

		Window& operator=(const Window& window);

		void setContext();
		void setViewport(int width, int height);
		void update();
		void render();
		void open();
		void close();

		//Events
		
		void registerEvents();

		void onClose(const std::function<void()>& callback);
		void onResize(const std::function<void(int, int)>& callback);
		void onFocus(const std::function<void(bool)>& callback);

	private:
		GLFWwindow* glfwWindow;

		int width, height;
		std::string title;

		std::function<void()> onCloseCallback;
		std::function<void(int, int)> onResizeCallback;
		std::function<void(bool)> onFocusCallback;

		static void onClose(GLFWwindow* window);
		static void onResize(GLFWwindow* window, int width, int height);
		static void onFocus(GLFWwindow* window, int focused);
	};

	// ---------- Window Class ----------

	Window::Window() { }

	Window::Window(const std::string& title, const int& width, const int& height) {
		this->title = title;
		this->width = width;
		this->height = height;
	}

	Window& Window::operator=(const Window& window)
	{
		glfwDestroyWindow(glfwWindow);

		title = window.title;
		width = window.width;
		height = window.height;

		onCloseCallback = window.onCloseCallback;
		onResizeCallback = window.onResizeCallback;

		return *this;
	}

	void Window::setContext() {
		glfwMakeContextCurrent(glfwWindow);
	}

	void Window::setViewport(int width, int height) {
		glViewport(0, 0, width, height);
	}
	
	void Window::update() {
		if (glfwWindow != nullptr) {
			glfwPollEvents();
			//printf("%i, %i\n", width, height);
		}
	}

	void Window::render() {
		if (glfwWindow != nullptr) {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glClearColor(0.0f, 0.5f, 0.2f, 1.0f);

			glfwSwapBuffers(glfwWindow);
		}
	}

	void Window::open() {
		glfwWindow = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
		if (glfwWindow == NULL) {
			fprintf(stderr, "Failed to open GLFW window. Check OpenGL compatibility");
			glfwTerminate();
			throw std::runtime_error("Failed to open GLFW window. Check OpenGL compatibility");
		}

		glfwSetWindowUserPointer(glfwWindow, static_cast<void*>(this));
		registerEvents();
	}

	void Window::close() {
		glfwSetWindowShouldClose(glfwWindow, 1);
		glfwDestroyWindow(glfwWindow);
	}

	void Window::registerEvents() {
		glfwSetWindowCloseCallback(glfwWindow, onClose);
		glfwSetFramebufferSizeCallback(glfwWindow, onResize);
	}

	void Window::onClose(const std::function<void()>& callback) {
		onCloseCallback = callback;
		glfwSetWindowCloseCallback(glfwWindow, onClose);
	}

	void Window::onResize(const std::function<void(int, int)>& callback) {
		onResizeCallback = callback;
		glfwSetFramebufferSizeCallback(glfwWindow, onResize);
	}

	void Window::onFocus(const std::function<void(bool)>& callback) {
		onFocusCallback = callback;
		glfwSetWindowFocusCallback(glfwWindow, onFocus);
	}

	void Window::onClose(GLFWwindow* window) {
		Window* self = static_cast<Window*>(glfwGetWindowUserPointer(window));
		if (self->onCloseCallback) self->onCloseCallback();
	}
	void Window::onResize(GLFWwindow* window, int width, int height) {
		Window* self = static_cast<Window*>(glfwGetWindowUserPointer(window));
		self->width = width;
		self->height = height;
		if (self->onResizeCallback) self->onResizeCallback(width, height);
	}
	void Window::onFocus(GLFWwindow* window, int focused) {
		Window* self = static_cast<Window*>(glfwGetWindowUserPointer(window));
		if (self->onFocusCallback) self->onFocusCallback(focused);
	}

	class Renderer 
	{
	public:

	private:

	};
}