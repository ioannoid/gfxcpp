#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <exception>
#include <functional>
#include <iostream>

namespace gfxcpp {

class engine {
public:
	engine();
	~engine();

	void init_gl();
	void run(const std::function<void()>& user_run);
	const bool& is_running();
	void end_loop();
	void exit(const int& error);

	void set_viewport(const int& x, const int& y, const int& width,
					  const int& height);

private:
	bool running;
};

class engine_error : public std::exception {
public:
	engine_error(const std::string& error) : error(error) {}
	inline const char* what() const noexcept override { return error.c_str(); }

private:
	std::string error;
};

} // namespace gfxcpp

#endif // ENGINE_HPP
