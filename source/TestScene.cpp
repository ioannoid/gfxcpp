#include "TestScene.hpp"

TestScene::TestScene()
{
    // triangle = Engine::Object({-.5f, -0.5f, 0.0f,
    //                             0.5f, -0.5f, 0.0f,
    //                             0.0f,  0.5f, 0.0f});
    square = Engine::Object({0.0f, -0.5f, 0.0f,
                             1.0f, -0.5f, 0.0f,
                             1.0f,  0.5f, 0.0f,
                             1.0f,  0.5f, 0.0f,
                             0.0f, -0.5f, 0.0f,
                             0.0f, 0.5f, 0.0f});
    
    // triangle.loadTexture({0.0f, 0.0f, 1.0f, 0.0f, 0.5f, 1.0f}, "box.jpg");
    // square.loadColors({1.0f, 0.0f, 0.0f, 1.0f,
    //                    1.0f, 1.0f, 1.0f, 1.0f,
    //                    0.0f, 0.0f, 1.0f, 1.0f,
    //                    0.0f, 0.0f, 1.0f, 1.0f,
    //                    1.0f, 0.0f, 0.0f, 1.0f,
    //                    0.0f, 1.0f, 0.0f, 1.0f});
    square.loadTexture({0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f}, "box.jpg");

    shader.loadVertex("shader.vert");
    shader.loadFragment("shader.frag");
    shader.link();
}

void TestScene::render()
{
    shader.use();
    //triangle.render();
    square.render();
}

void TestScene::update()
{
    //triangle.update();
}