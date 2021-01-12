#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Scene.hpp"
#include "Object.hpp"
#include "Shader.hpp"

class TestScene : public Engine::Scene
{
public:
    TestScene ();
    
    virtual void render();
    virtual void update();
private:
    Engine::Object triangle;
    Engine::Object square;
    Engine::Shader shader;
};