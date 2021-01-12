#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Engine {
    class Scene
    {
    public:
        Scene () {}
        
        virtual void update() = 0;
        virtual void render() = 0;
    private:
    };
}