#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <exception>
#include <iostream>
#include <functional>

#include "Window.hpp"
namespace Engine {
	class Window;
	class Game
	{
	public:
		Game();

		void initGl();
		void setWindow(Window& window);
		const Window& getWindow() const;

		void run();
		void update();
		void render();
		void clean();

		bool isRunning() const;
		void close();

	private:
		bool running = false;
		Window* window;

		double limitUPS = 1.0 / 60.0;
	};
}