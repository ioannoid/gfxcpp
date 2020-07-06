#pragma once

#include <GL/glew.h>
#include <glfw/glfw3.h>

#include <exception>
#include <iostream>
#include <vector>
#include <string>
#include <functional>

namespace Engine
{
	class Game
	{
	public:
		Game();

		void initGl();
		void run();
		void clean();

		bool isRunning();
		void close();

	private:
		bool running = false;

		void update();
		void render();
	};

	// ---------- Game Class ---------- 

	Game::Game() {
		if (!glfwInit()) {
			fprintf(stderr, "GLFW failed to initialize\n");
			throw std::runtime_error("GLFW failed to initialize");
		}

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
		while (isRunning())
		{
			update();
			render();
		}
		clean();
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
		Window(std::string title, int width, int height);

		void setContext();
		void update();
		void render();
		void close();

		//Events
		
		void registerEvents();
		void onClose(const std::function<void()>& callback);
		void wtf();

	private:
		GLFWwindow* glfwWindow;

		std::function<void()> onCloseCallback;

		static void onClose(GLFWwindow* window);
	};

	// ---------- Window Class ----------

	Window::Window() { }

	Window::Window(std::string title, int width, int height) {
		glfwWindowHint(GLFW_SAMPLES, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		glfwWindow = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
		if (glfwWindow == NULL) {
			fprintf(stderr, "Failed to open GLFW window. Check OpenGL compatibility");
			glfwTerminate();
			throw std::runtime_error("Failed to open GLFW window. Check OpenGL compatibility");
		}

		glfwSetWindowUserPointer(glfwWindow, static_cast<void*>(this));
		registerEvents();
	}

	void Window::setContext() {
		glfwMakeContextCurrent(0);
		glfwMakeContextCurrent(glfwWindow);
	}
	
	void Window::update() {
		glfwPollEvents();
	}

	void Window::render() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glClearColor(0.0f, 0.5f, 0.2f, 1.0f);

		glfwSwapBuffers(glfwWindow);
	}

	void Window::close() {
		glfwSetWindowShouldClose(glfwWindow, 1);
		//glfwDestroyWindow(glfwWindow);
	}

	void Window::registerEvents() {
		glfwSetWindowCloseCallback(glfwWindow, onClose);
	}

	void Window::onClose(const std::function<void()>& callback) {
		onCloseCallback = callback;
		glfwSetWindowCloseCallback(glfwWindow, onClose);
	}

	void Window::onClose(GLFWwindow* window) {
		Window* self = static_cast<Window*>(glfwGetWindowUserPointer(window));
		/*if (self->onCloseCallback) self->onCloseCallback();*/
		self->wtf();
	}

	void Window::wtf()
	{
		if(onCloseCallback) onCloseCallback();
	}
}