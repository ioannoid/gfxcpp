#ifndef SHADER_HPP
#define SHADER_HPP

#include <GL/glew.h>

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

private:
	engine& engine_ref;

	GLuint program;
};

} // namespace gfxcpp

#endif // SHADER_HPP
