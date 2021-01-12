#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <exception>
#include <iostream>
#include <functional>

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
}