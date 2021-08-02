#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <vector>
#include <memory>

#include "Texture2D.hpp"

namespace Engine {
    class Sprite {
    public:
        Sprite();
        Sprite(Sprite&& sprite);
        Sprite(Texture2D& texture);
        Sprite(Texture2D& texture, int width, int height, int xpos = 0, int ypos = 0);
        ~Sprite();

        Sprite& operator=(Sprite& sprite) = delete;
        Sprite& operator=(Sprite&& sprite);
        
        void render();
        void render(const int& num);

        void setPosition(const glm::vec3& pos);
        glm::mat4 getPosition();
        void setRotation(const glm::vec3& rot, const float& angle);
        glm::mat4 getRotation();
        void setScale(const glm::vec3& scale);
        glm::mat4 getScale();

        void translate(const glm::vec3& trans);

        const glm::mat4& getTransform();

    private:
        GLuint vao, vbo;
        Texture2D* texture;

        glm::mat4 position;
        glm::mat4 rotation;
        glm::mat4 scale;
        glm::mat4 transform;

        bool recalculate = false;

        inline static const GLfloat vertices[] = {
            -0.5f, -0.5f, 0.0f,   0.0f, 0.0f,
             0.5f, -0.5f, 0.0f,   1.0f, 0.0f,
             0.5f,  0.5f, 0.0f,   1.0f, 1.0f,

             0.5f,  0.5f, 0.0f,   1.0f, 1.0f,
            -0.5f, -0.5f, 0.0f,   0.0f, 0.0f,
            -0.5f,  0.5f, 0.0f,   0.0f, 1.0f
        };
    };
}