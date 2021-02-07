#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Scene.hpp"
#include "Object.hpp"
#include "Shader.hpp"
#include "Window.hpp"
#include "Game.hpp"
#include "Texture2D.hpp"
#include "Sprite.hpp"

class TestScene : public Engine::Scene
{
public:
    TestScene(Engine::Game& game, Engine::Window& window);
    
    virtual void render();
    virtual void update();

    virtual void onKey(int key, int scancode, int action, int mods);
    virtual void onMouseButton(int button, int action, int mods, double xpos, double ypos);
    virtual void onMouseMove(double xpos, double ypos);
private:
    Engine::Game& game;
    Engine::Window& window;

    Engine::Texture2D pieceTexture;
    Engine::Sprite piece;

    Engine::Texture2D boardTexture;
    Engine::Sprite board;


    Engine::Shader shader;

    float currentFrame = 0;

    // bool lbuttondown = false;
};