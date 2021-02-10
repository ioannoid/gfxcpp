#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "Resource.hpp"
namespace Engine {
    class Texture2D : public Engine::Resource {
    public:
        friend class Sprite;

        Texture2D();
        Texture2D(const char* texture);
        ~Texture2D();

        const int& getWidth();
        const int& getHeight();

        virtual void free();

    private:
        GLuint texture;
        int width, height;
    };
}