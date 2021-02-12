#pragma once


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <sstream>
#include <fstream>
#include <vector>

namespace Engine {
    class Shader
    {
    public:
        Shader();
        Shader(const char* vertexPath, const char* fragmentPath);
        ~Shader();

        Shader& operator=(Shader& shader) = delete;
        Shader& operator=(Shader&& shader);

        void use();
        void setInt(const char* name, const int& value);
        void setFloat(const char* name, const float& value);
        void setBool(const char* name, const bool& value);
        void setVec2(const char* name, const glm::vec2& value);
        void setMat4(const char* name, const glm::mat4& value);

    private:
        GLuint vertex, fragment, program = 0;
    };
}