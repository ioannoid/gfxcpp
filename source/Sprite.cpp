#include "Sprite.hpp"

namespace Engine {
    Sprite::Sprite() { }

    Sprite::Sprite(Sprite&& sprite) {
        vao = std::move(sprite.vao);
        sprite.vao = 0;
        vbo = std::move(sprite.vbo);
        sprite.vbo = 0;
        
        texture = sprite.texture;

        position = std::move(sprite.position);
        rotation = std::move(sprite.rotation);
        scale = std::move(sprite.scale);
        transform = std::move(sprite.transform);

        recalculate = sprite.recalculate;
    }

    Sprite::Sprite(Texture2D& texture) {
        this->texture = &texture;

        glGenVertexArrays(1, &vao);
        glGenBuffers(1, &vbo);

        glBindVertexArray(vao);
        
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) , vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), static_cast<char*>(0) + (3 * sizeof(GLfloat)));
        glEnableVertexAttribArray(2);

        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        position = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
        rotation = glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        scale = glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));
        transform = position * rotation * scale;
    }

    Sprite::Sprite(Texture2D& texture, int width, int height, int xpos, int ypos) {
        this->texture = &texture;
        
        std::vector<GLfloat> newUvs(vertices, vertices+30);

        newUvs.at(3) = static_cast<float>(xpos)/texture.width;
        newUvs.at(4) = static_cast<float>(ypos)/texture.height;

        newUvs.at(8) = (static_cast<float>(xpos)/texture.width) + (static_cast<float>(width)/texture.width);
        newUvs.at(9) = static_cast<float>(ypos)/texture.height;

        newUvs.at(13) = (static_cast<float>(xpos)/texture.width) + (static_cast<float>(width)/texture.width);
        newUvs.at(14) = (static_cast<float>(ypos)/texture.height) + (static_cast<float>(height)/texture.height);

        newUvs.at(18) = (static_cast<float>(xpos)/texture.width) + (static_cast<float>(width)/texture.width);
        newUvs.at(19) = (static_cast<float>(ypos)/texture.height) + (static_cast<float>(height)/texture.height);

        newUvs.at(23) = static_cast<float>(xpos)/texture.width;
        newUvs.at(24) = static_cast<float>(ypos)/texture.height;

        newUvs.at(28) = static_cast<float>(xpos)/texture.width;
        newUvs.at(29) = (static_cast<float>(ypos)/texture.height) + (static_cast<float>(height)/texture.height);

        glGenVertexArrays(1, &vao);
        glGenBuffers(1, &vbo);

        glBindVertexArray(vao);
        
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, newUvs.size() * sizeof(GLfloat), newUvs.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), static_cast<char*>(0) + (3 * sizeof(GLfloat)));
        glEnableVertexAttribArray(2);

        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        position = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
        rotation = glm::rotate(glm::mat4(1.0f), glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        scale = glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));
        transform = position * rotation * scale;
    }

    Sprite::~Sprite() {
        glDeleteBuffers(1, &vbo);
        glDeleteVertexArrays(1, &vao);
    }

    Sprite& Sprite::operator=(Sprite&& sprite) {
        vao = std::move(sprite.vao);
        sprite.vao = 0;
        vbo = std::move(sprite.vbo);
        sprite.vbo = 0;
        
        texture = sprite.texture;

        position = std::move(sprite.position);
        rotation = std::move(sprite.rotation);
        scale = std::move(sprite.scale);
        transform = std::move(sprite.transform);

        recalculate = sprite.recalculate;
        return *this;
    }

    void Sprite::render() {
        glBindTexture(GL_TEXTURE_2D, texture->texture);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 6);
    }

    void Sprite::render(const int& num) {
        glBindTexture(GL_TEXTURE_2D, texture->texture);
        glBindVertexArray(vao);
        glDrawArraysInstanced(GL_TRIANGLES, 0, 6, num);
    }

    void Sprite::setPosition(const glm::vec3& pos) {
        position = glm::translate(glm::mat4(1.0f), pos);
        recalculate = true;
    }

    glm::mat4 Sprite::getPosition() {
        return position;
    }

    void Sprite::setRotation(const glm::vec3& rot, const float& angle) {
        rotation = glm::rotate(glm::mat4(1.0f), glm::radians(angle), rot);
        recalculate = true;
    }

    glm::mat4 Sprite::getRotation() {
        return rotation;
    }

    void Sprite::setScale(const glm::vec3& scale) {
        this->scale = glm::scale(glm::mat4(1.0f), scale);
        recalculate = true;
    }

    glm::mat4 Sprite::getScale() {
        return scale;
    }

    void Sprite::translate(const glm::vec3& trans) {
        position = glm::translate(position, trans);
        recalculate = true;
    }

    const glm::mat4& Sprite::getTransform() {
        if(recalculate) {
            transform = position * rotation * scale;
            recalculate = false;
        }

        return transform;
    }
}