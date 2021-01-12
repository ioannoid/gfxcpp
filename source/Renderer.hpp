#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <exception>
#include <iostream>
#include <vector>
#include <functional>

#include "Object.hpp"

namespace Engine {
    class Renderer
    {
    public:
        Renderer();

        void render();
        void addObject();

    private:
        std::vector<Object> objects;

    };
}