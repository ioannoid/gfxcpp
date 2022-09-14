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

    delete[] buffer;

    program = glCreateProgram();
    glAttachShader(program, vert_shader);
    glAttachShader(program, frag_shader);
    glLinkProgram(program);
}

shader::~shader() {}

void shader::use_program() { glUseProgram(program); }
