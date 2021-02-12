#include "TestScene.hpp"

TestScene::TestScene(Engine::Game& game) : Engine::Scene(game) {
    std::function<void()>();
    piece = Engine::Sprite(pieceTexture, 16, 16);
    piece.setScale(glm::vec3(100.0f, 100.0f, 0.0f));

    piece1Texture = Engine::Texture2D("bean.png");
    piece1 = Engine::Sprite(piece1Texture, 860, 562);
    piece1.setScale(glm::vec3(100.0f, 100.0f, 0.0f));

    boardTexture = Engine::Texture2D("board.png");
    board = Engine::Sprite(boardTexture, 33, 33);
    board.setScale(glm::vec3(100.0f, 100.0f, 0.0f));

    shader = Engine::Shader("shader.vert", "shader.frag");

}

void TestScene::update() {
    currentFrame+=0.5;
    if(currentFrame == 360) currentFrame = 0;

    projection = glm::ortho(0.0f, (float) game.getWindow().getWidth(), (float) game.getWindow().getHeight(), 0.0f, 0.1f, 100.0f);

    piece.setPosition(glm::vec3((game.getWindow().getWidth()/2.0f) + (100 * cos(glm::radians(currentFrame))), (game.getWindow().getHeight()/2.0f) + (100 * sin(glm::radians(currentFrame))), -0.5f));
    piece1.setPosition(glm::vec3((game.getWindow().getWidth()/2.0f) + (100 * cos(glm::radians(currentFrame)+3.1415926)), (game.getWindow().getHeight()/2.0f) + (100 * sin(glm::radians(currentFrame)+3.1415926)), -0.5f));
    board.setPosition(glm::vec3(game.getWindow().getWidth()/2.0f, game.getWindow().getHeight()/2.0f, -1.0f));
}

void TestScene::render() {
    shader.use();
    //shader.setInt("currentFrame", currentFrame);
    //shader.setInt("frames", 10);
    shader.setMat4("projection", projection);//glm::perspective(70.0f, (float) game.getWindow().getWidth() / game.getWindow().getHeight(), 1.0f, 150.0f));

    shader.setMat4("transform", piece.getTransform());
    piece.render();

    shader.setMat4("transform", piece1.getTransform());
    piece1.render();

    shader.setMat4("transform", board.getTransform());
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
    //std::cout << xpos << " " << ypos << std::endl;
}