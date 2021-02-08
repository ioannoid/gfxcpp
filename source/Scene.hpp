#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Game.hpp"
namespace Engine {
    class Game;
    class Scene
    {
    public:
        friend class Window;
        Scene (Game& game) : game(game) { }
        
    protected:
        virtual void update() = 0;
        virtual void render() = 0;

        virtual void onKey(int key, int scancode, int action, int mod) { }
        virtual void onMouseButton(int key, int action, int mods, double xpos, double ypos) { }
        virtual void onMouseMove(double xpos, double ypos) { }
    private:
        Game& game;
    };
}