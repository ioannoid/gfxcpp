#include "TestScene.hpp"

TestScene::TestScene(Engine::Game& game, Engine::Window& window) : game(game), window(window) {
    // triangle = Engine::Object({-.5f, -0.5f, 0.0f,
    //                             0.5f, -0.5f, 0.0f,
    //                             0.0f,  0.5f, 0.0f});
    // square = Engine::Object({0.0f, -0.5f, 0.0f,
    //                          1.0f, -0.5f, 0.0f,
    //                          1.0f,  0.5f, 0.0f,
    //                          1.0f,  0.5f, 0.0f,
    //                          0.0f, -0.5f, 0.0f,
    //                          0.0f, 0.5f, 0.0f});
    
    // triangle.loadTexture({0.0f, 0.0f, 1.0f, 0.0f, 0.5f, 1.0f}, "box.jpg");
    // square.loadColors({1.0f, 0.0f, 0.0f, 1.0f,
    //                    1.0f, 1.0f, 1.0f, 1.0f,
    //                    0.0f, 0.0f, 1.0f, 1.0f,
    //                    0.0f, 0.0f, 1.0f, 1.0f,
    //                    1.0f, 0.0f, 0.0f, 1.0f,
    //                    0.0f, 1.0f, 0.0f, 1.0f});
    // square.loadTexture({0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f}, "box.jpg");

    texture = Engine::Texture2D("box.jpg");

    shader.loadVertex("shader.vert");
    shader.loadFragment("shader.frag");
    shader.link();
}

void TestScene::render() {
    shader.use();
    spriteRenderer.render(texture);
    // triangle.render();
    // square.render();
}

void TestScene::update() {
    //triangle.update();
}

void TestScene::onKey(int key, int scancode, int action, int mods) {
    if(key == GLFW_KEY_ESCAPE) { 
        window.close();
        game.close();
    }
}

void TestScene::onMouseButton(int button, int action, int mods, double xpos, double ypos) {
    // if(button == GLFW_MOUSE_BUTTON_1 && action == GLFW_PRESS) lbuttondown = true;
    // else if(button == GLFW_MOUSE_BUTTON_1 && action == GLFW_RELEASE) lbuttondown = false;
}

void TestScene::onMouseMove(double xpos, double ypos) {
    // if(lbuttondown) std::cout << xpos << " " << ypos << std::endl;
}