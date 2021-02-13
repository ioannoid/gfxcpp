#include "Board.hpp"

Board::Board(Engine::Game& game) : Engine::Scene(game) {
    boardTexture = Engine::Texture2D("board.png");
    board = Engine::Sprite(boardTexture);
    board.setScale(glm::vec3(200.0f, 200.0f, 200.0f));

    shader = Engine::Shader("board.vert", "board.frag");
}
    
void Board::update() {
    projection = glm::ortho(0.0f, (float) game.getWindow().getWidth(), (float) game.getWindow().getHeight(), 0.0f, 0.1f, 100.0f);
    board.setPosition(glm::vec3(game.getWindow().getWidth()/2.0f, game.getWindow().getHeight()/2.0f, -1.0f));
    color += 0.01;
    if(color >= 3.14*2) color = 0;
}

void Board::render() {
    shader.use();

    shader.setMat4("projection", projection);
    shader.setMat4("transform", board.getTransform());
    shader.setFloat("color", color);
    board.render();
}

void Board::onKey(int key, int scancode, int action, int mods) {

}

void Board::onMouseButton(int button, int action, int mods, double xpos, double ypos) {

}

void Board::onMouseMove(double xpos, double ypos) {
    
}