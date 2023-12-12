#ifndef SHADER_HPP
#define SHADER_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <fstream>
#include <sstream>
#include <string>

#include "engine.hpp"

namespace gfxcpp {

class shader {
public:
	shader(engine& engine_ref, const std::string& vert_path,
		   const std::string& frag_path);
	~shader();

	void use_program();

    void set_int(const char* name, const int& value);
    void set_float(const char* name, const float& value);
    void set_bool(const char* name, const bool& value);
    void set_vec2(const char* name, const glm::vec2& value);
    void set_mat4(const char* name, const glm::mat4& value);

private:
	engine& engine_ref;

	GLuint program;
};

} // namespace gfxcpp

#endif // SHADER_HPP
