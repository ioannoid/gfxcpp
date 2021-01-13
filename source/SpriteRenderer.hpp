#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "Texture2D.hpp"

namespace Engine {
    class SpriteRenderer {
    public:
        SpriteRenderer();
        ~SpriteRenderer();

        void render(Texture2D& texture);
    private:
        GLuint vao, vbo;

        inline static const GLfloat vertices[] = {
            0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
            1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 
        
            0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
            1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
            1.0f, 0.0f, 0.0f, 1.0f, 0.0f
        };
    };
}