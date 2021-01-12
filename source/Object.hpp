#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>

#include "Shader.hpp"

namespace Engine {
    class Object
    {
    public:
        Object();
        Object(const std::vector<GLfloat>& vertices);

        void loadColors(const std::vector<GLfloat>& colors);
        void loadUvs(const std::vector<GLfloat>& uvs);
        void loadNormals(const std::vector<GLfloat>& normals);

        void render();
        void update();

    private:
        GLuint vao;
        GLuint vbo, cbo, ubo, nbo, ibo;
        size_t vsize, csize, usize, nsize;
    };
}