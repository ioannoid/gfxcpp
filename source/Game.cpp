#include "Game.hpp"

namespace Engine {
    Game::Game() {
        if (!glfwInit()) {
            fprintf(stderr, "GLFW failed to initialize\n");
            throw std::runtime_error("GLFW failed to initialize");
        }

        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);

        running = true;
    }

    void Game::initGl() {
        glewExperimental = true;
        if (glewInit() != GLEW_OK) {
            fprintf(stderr, "GLEW failed to initialize\n");
            glfwTerminate();
            throw std::runtime_error("GLEW failed to initialize");
        }
    }

    void Game::clean() {
        glfwTerminate();
    }

    void Game::run() {
        // std::thread thread(&Engine::Game::render, this);
        // thread.detach();
        

        while(running) {
            render();
            update();

        }

        clean();
    }

    void Game::onRender(const std::function<void()>& render) {
        this->render = render;
    }

    void Game::onUpdate(const std::function<void()>& update) {
        this->update = update;
    }

    bool Game::isRunning() {
        return running;
    }

    void Game::close() {
        running = false;
    }
}