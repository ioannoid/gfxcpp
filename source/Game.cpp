#include "Game.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.hpp"
namespace Engine {
    Game::Game() {
        stbi_set_flip_vertically_on_load(true);

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

    void Game::setWindow(Window& window) {
        this->window = &window;
        window.open();
    }

	const Window& Game::getWindow() const {
        return *window;
    }

    void Game::initGl() {
        glewExperimental = true;
        if (glewInit() != GLEW_OK) {
            fprintf(stderr, "GLEW failed to initialize\n");
            glfwTerminate();
            throw std::runtime_error("GLEW failed to initialize");
        }

        glEnable(GL_DEPTH_TEST);
    }

    void Game::clean() {
        glfwTerminate();
    }

    void Game::run() {
        // std::thread thread(&Engine::Game::render, this);
        // thread.detach();

        double lastTime = glfwGetTime(), timer = lastTime;
        double deltaTime = 0, nowTime = 0;
        int frames = 0 , updates = 0;

        while(running) {
            nowTime = glfwGetTime();
            deltaTime += (nowTime - lastTime) / limitUPS;
            lastTime = nowTime;

            glfwPollEvents();

            while(deltaTime >= 1.0) {
                update();
                updates++;
                deltaTime--;
            }

            render();
            frames++;

            if(glfwGetTime() - timer > 1.0) {
                timer++;
                printf("FPS: %i, UPS: %i\n", frames, updates);
                updates = 0, frames = 0;
            }
        }

        clean();
    }

    void Game::update() {
        window->update();
    }

    void Game::render() {
        window->render();
    }

    bool Game::isRunning() const {
        return running;
    }

    void Game::close() {
        running = false;
    }
}