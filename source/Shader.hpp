#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>
#include <sstream>
#include <fstream>
#include <vector>

namespace Engine {
    class Shader
    {
    public:
        friend class Scene;

        Shader ();

        void loadVertex(const char* vertexPath);
        void loadFragment(const char* fragmentPath);

        void link(); //Deletes shaders after linking
        void use();

    private:
        GLuint vertex, fragment, program = 0;
    };
}