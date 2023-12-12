#include "shader.hpp"

using namespace gfxcpp;

shader::shader(engine& engine_ref, const std::string& vert_path,
			   const std::string& frag_path)
	: engine_ref(engine_ref) {
	std::ifstream file(vert_path);
	file.seekg(0, std::ios::end);
	size_t size = file.tellg();
	char* buffer = new char[size];
	file.seekg(0);
	file.read(buffer, size);
	file.close();

	GLuint vert_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vert_shader, 1, &buffer, nullptr);
	glCompileShader(vert_shader);

	int success;
	char info_log[512];
	glGetShaderiv(vert_shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vert_shader, 512, NULL, info_log);
		std::cerr << "Error compiling vertex shader:\n" << info_log << "\n";
		engine_ref.exit(4);
	}

	delete[] buffer;

	file.open(frag_path);
	file.seekg(0, std::ios::end);
	size = file.tellg();
	buffer = new char[size];
	file.seekg(0);
	file.read(buffer, size);
	file.close();

	GLuint frag_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(frag_shader, 1, &buffer, nullptr);
	glCompileShader(frag_shader);

	glGetShaderiv(frag_shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(frag_shader, 512, NULL, info_log);
		std::cerr << "Error compiling fragment shader:\n" << info_log << "\n";
		engine_ref.exit(4);
	}

	delete[] buffer;

	program = glCreateProgram();
	glAttachShader(program, vert_shader);
	glAttachShader(program, frag_shader);
	glLinkProgram(program);

	glGetShaderiv(program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(program, 512, NULL, info_log);
		std::cerr << "Error linking shaders:\n" << info_log << "\n";
		engine_ref.exit(4);
	}

	glDeleteShader(vert_shader);
	glDeleteShader(frag_shader);
}

shader::~shader() { glDeleteProgram(program); }

void shader::use_program() { glUseProgram(program); }

void shader::set_int(const char* name, const int& value) {
    glUniform1i(glGetUniformLocation(program, name), value);
}

void shader::set_float(const char* name, const float& value) {
    glUniform1f(glGetUniformLocation(program, name), value);
}

void shader::set_vec2(const char* name, const glm::vec2& value) {
    glUniform2fv(glGetUniformLocation(program, name), 1, glm::value_ptr(value));
}
