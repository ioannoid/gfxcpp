#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Engine {
    class Scene
    {
    public:
        Scene () {}
        
        virtual void render() = 0;
        virtual void update() = 0;
    private:
    };
}