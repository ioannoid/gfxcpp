#include "TestScene.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

TestScene::TestScene(Engine::Game& game) : Engine::Scene(game) {
    pieceTexture = Engine::Texture2D("doggy.png");
    piece = Engine::Sprite(pieceTexture, 16, 16);
    piece.setScale(glm::vec3(100.0f, 100.0f, 0.0f));
    piece.setPosition(glm::vec3((float) game.getWindow().getWidth() / 2, 0, -1.0f));

    boardTexture = Engine::Texture2D("Board.png");
    board = Engine::Sprite(boardTexture, 33, 33);
    board.setPosition(glm::vec3((float) game.getWindow().getWidth() / 2, (float) game.getWindow().getHeight() / 2, -1.5f));
    board.setScale(glm::vec3(100.0f, 100.0f, 0.0f));

    shader = Engine::Shader("shader.vert", "shader.frag");
}

void TestScene::update() {
    currentFrame+=0.5;
    if(currentFrame == 360) currentFrame = 0;
    piece.setRotation(glm::vec3(0.0f, 0.0f, 1.0f), currentFrame);
    piece.translate(glm::vec3(cos(glm::radians(currentFrame)), sin(glm::radians(currentFrame)), 0.0f));
}

void TestScene::render() {
    shader.use();
    //shader.setInt("currentFrame", currentFrame);
    //shader.setInt("frames", 10);
    shader.setMat("projection", glm::ortho(0.0f, (float) game.getWindow().getWidth(), 0.0f, (float) game.getWindow().getHeight(), 0.1f, 100.0f));//glm::perspective(70.0f, (float) game.getWindow().getWidth() / game.getWindow().getHeight(), 1.0f, 150.0f));
    shader.setMat("transform", piece.getTransform());
    piece.render();
    shader.setMat("transform", board.getTransform());
    board.render();
    // triangle.render();
    // square.render();
}

void TestScene::onKey(int key, int scancode, int action, int mods) {
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) { 
        
    }
}

void TestScene::onMouseButton(int button, int action, int mods, double xpos, double ypos) {
    // if(button == GLFW_MOUSE_BUTTON_1 && action == GLFW_PRESS) lbuttondown = true;
    // else if(button == GLFW_MOUSE_BUTTON_1 && action == GLFW_RELEASE) lbuttondown = false;
}

void TestScene::onMouseMove(double xpos, double ypos) {
    // if(lbuttondown) std::cout << xpos << " " << ypos << std::endl;
}