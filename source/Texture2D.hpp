#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace Engine {
    class Texture2D {
    public:
        friend class SpriteRenderer;

        Texture2D();
        Texture2D(const char* texture);
        ~Texture2D();

    private:
        GLuint texture;
        int width;
        int height;
    };
}