#include "Window.hpp"

namespace Engine {
    Window::Window() { }

	Window::Window(const std::string& title, const int& width, const int& height) {
		this->title = title;
		this->width = width;
		this->height = height;
	}

	// Window& Window::operator=(const Window& window) {
	// 	glfwDestroyWindow(glfwWindow);

	// 	title = window.title;
	// 	width = window.width;
	// 	height = window.height;

	// 	onCloseCallback = window.onCloseCallback;
	// 	onResizeCallback = window.onResizeCallback;
	// 	onFocus

	// 	return *this;
	// }

	void Window::setContext() {
		glfwMakeContextCurrent(glfwWindow);
		glfwSwapInterval(0);
	}

	void Window::setViewport(int width, int height) {
		glViewport(0, 0, width, height);
	}

	void Window::update() {
		if (glfwWindow != nullptr) {
			//printf("%i, %i\n", width, height);
            currentScene->update();
		}
	}

	void Window::render() {
		if (glfwWindow != nullptr && !glfwWindowShouldClose(glfwWindow)) {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			currentScene->render();

			glClearColor(0.0f, 1.0f, 0.5f, 1.0f);

			glBindVertexArray(0);
			glBindTexture(GL_TEXTURE_2D, 0);
			glfwSwapBuffers(glfwWindow);
		}
	}

	void Window::open() {
		glfwWindow = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
		if (glfwWindow == nullptr) {
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

    void Window::setScene(Scene& currentScene) {
        this->currentScene = &currentScene;
    }

	void Window::registerEvents() {
		glfwSetWindowCloseCallback(glfwWindow, onClose);
		glfwSetFramebufferSizeCallback(glfwWindow, onResize);
		glfwSetWindowFocusCallback(glfwWindow, onFocus);
		glfwSetKeyCallback(glfwWindow, onKey);
		glfwSetMouseButtonCallback(glfwWindow, onMouseButton);
		glfwSetCursorPosCallback(glfwWindow, onMouseMove);
	}

	void Window::onClose(const std::function<void()>& callback) {
		onCloseCallback = callback;
		if(glfwWindow != NULL) glfwSetWindowCloseCallback(glfwWindow, onClose);
	}

	void Window::onResize(const std::function<void(int, int)>& callback) {
		onResizeCallback = callback;
		if(glfwWindow != NULL) glfwSetFramebufferSizeCallback(glfwWindow, onResize);
	}

	void Window::onFocus(const std::function<void(bool)>& callback) {
		onFocusCallback = callback;
		if(glfwWindow != NULL) glfwSetWindowFocusCallback(glfwWindow, onFocus);
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

	void Window::onKey(GLFWwindow* window, int key, int scancode, int action, int mods) {
		Window* self = static_cast<Window*>(glfwGetWindowUserPointer(window));
		self->currentScene->onKey(key, scancode, action, mods);
	}

	void Window::onMouseButton(GLFWwindow* window, int button, int action, int mods) {
		Window* self = static_cast<Window*>(glfwGetWindowUserPointer(window));
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		self->currentScene->onMouseButton(button, action, mods, xpos, ypos);
	}

	void Window::onMouseMove(GLFWwindow* window, double xpos, double ypos) {
		Window* self = static_cast<Window*>(glfwGetWindowUserPointer(window));
		self->currentScene->onMouseMove(xpos, ypos);
	}
}