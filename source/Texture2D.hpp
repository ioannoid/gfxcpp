#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace Engine {
    class Texture2D {
    public:
        friend class Sprite;

        Texture2D();
        Texture2D(const char* texture);
        ~Texture2D();

        const int& getWidth();
        const int& getHeight();

    private:
        GLuint texture;
        int width, height;
    };
}