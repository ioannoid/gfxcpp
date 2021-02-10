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

class Board : public Engine::Scene
{
public:
    Board(Engine::Game& game);
    
    virtual void update();
    virtual void render();

    virtual void onKey(int key, int scancode, int action, int mods);
    virtual void onMouseButton(int button, int action, int mods, double xpos, double ypos);
    virtual void onMouseMove(double xpos, double ypos);
private:

    Engine::Texture2D pieceTexture;
    Engine::Sprite piece;

    Engine::Shader shader;

    glm::mat4 projection;

    float currentFrame = 0;

    // bool lbuttondown = false;
};