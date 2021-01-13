#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>
#include <iostream>

namespace Engine {
    class Object
    {
    public:
        Object();
        Object(const std::vector<GLfloat>& vertices);
        ~Object();

        void loadColors(const std::vector<GLfloat>& colors);
        void loadTexture(const std::vector<GLfloat>& uvs, const char* texture);
        void loadNormals(const std::vector<GLfloat>& normals);

        void update();
        void render();

    private:
        GLuint vao;
        GLuint vbo, cbo, ubo, nbo, ibo;
        GLuint texture;
        size_t vsize, csize, usize, nsize;
    };
}