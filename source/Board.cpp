#include "Board.hpp"

float map(float pix, float pixmax, float min, float max) {
    return (pix/pixmax) * (max-min) + min;
}

Board::Board(Engine::Game& game) : Engine::Scene(game) {
    //boardTexture = Engine::Texture2D("board.png");
    //board = Engine::Sprite(boardTexture);
    //board.setScale(glm::vec3(200.0f, 200.0f, 200.0f));

    boardTexture = Engine::Texture2D();
    board = Engine::Sprite(boardTexture);
    //board.setScale(glm::vec3(30.0f, 30.0f, 0.0f));
    board.setScale(glm::vec3((float) game.getWindow().getWidth(), (float) game.getWindow().getHeight(), 0.0f));

    //shader = Engine::Shader("board.vert", "board.frag");
    shader = Engine::Shader("mandel.vert", "mandel.frag");
}

void Board::update() {
    projection = glm::ortho(0.0f, (float) game.getWindow().getWidth(), (float) game.getWindow().getHeight(), 0.0f, 0.1f, 100.0f);
    //board.setPosition(glm::vec3(game.getWindow().getWidth()/2.0f - 300.f, game.getWindow().getHeight()/2.0f - 300.f, -1.0f));
    board.setScale(glm::vec3((float) game.getWindow().getWidth(), (float) game.getWindow().getHeight(), 0.0f));
    board.setPosition(glm::vec3(game.getWindow().getWidth()/2.0f, game.getWindow().getHeight()/2.0f, -1.0f));
    test += 100;
}

void Board::render() {
    shader.use();

    shader.setMat4("projection", projection);

    shader.setMat4("position", board.getPosition());
    shader.setMat4("rotation", board.getRotation());
    shader.setMat4("scale", board.getScale());
    shader.setFloat("test", test);

    shader.setVec2("resolution", glm::vec2(game.getWindow().getWidth(), game.getWindow().getHeight()));
    board.render();
    //board.render(21*21);
    
    //shader.setMat4("transform", board.getTransform());
    //shader.setFloat("color", color);
    //board.render();
}

void Board::onKey(int key, int scancode, int action, int mods) {

}

void Board::onMouseButton(int button, int action, int mods, double xpos, double ypos) {

}

void Board::onMouseMove(double xpos, double ypos) {
    //cursorPos = glm::vec2(xpos, ypos);
}