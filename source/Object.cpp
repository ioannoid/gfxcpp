#include "Object.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.hpp"

namespace Engine 
{
    Object::Object() { }

    Object::Object(const std::vector<GLfloat>& vertices)
    {
        glGenVertexArrays(1, &vao);
        glGenBuffers(1, &vbo);

        vsize = vertices.size() * sizeof(GLfloat);
        // colorSize = color.size() * sizeof(GLfloat);
        // textureSize = texture.size() * sizeof(GLfloat);
        // normalSize = normal.size() * sizeof(GLfloat);

        glBindVertexArray(vao);
        
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, vsize, vertices.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(0);

        // if(colorSize) {
        //     glBufferSubData(GL_ARRAY_BUFFER, vertexSize, colorSize, color.data());
        //     glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, static_cast<char const*>(0) + vertexSize);
        //     glEnableVertexAttribArray(1);
        // }
        // if(textureSize) {
        //     glBufferSubData(GL_ARRAY_BUFFER, vertexSize+colorSize, textureSize, texture.data());
        //     glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, static_cast<char const*>(0) + vertexSize+colorSize);
        //     glEnableVertexAttribArray(2);
        // }
        // if(normalSize) {
        //     glBufferSubData(GL_ARRAY_BUFFER, vertexSize+colorSize+textureSize, normalSize, normal.data());
        //     glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 0, static_cast<char const*>(0) + vertexSize+colorSize+textureSize);
        //     glEnableVertexAttribArray(3);
        // }

        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void Object::loadColors(const std::vector<GLfloat>& colors) {
        glGenBuffers(1, &cbo);
        csize = colors.size() * sizeof(GLfloat);

        glBindVertexArray(vao);

        glBindBuffer(GL_ARRAY_BUFFER, cbo);
        glBufferData(GL_ARRAY_BUFFER, csize, colors.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(1);

        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void Object::loadTexture(const std::vector<GLfloat>& uvs, const char* texture) {
        glGenTextures(1, &this->texture);
        glBindTexture(GL_TEXTURE_2D, this->texture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        int width, height;
        GLubyte* data = stbi_load(texture, &width, &height, nullptr, 0);
        if(data) {
            glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else {
            std::cout << "failed to load texture" << std::endl;
        }
        stbi_image_free(data);

        glBindTexture(GL_TEXTURE_2D, 0);

        glGenBuffers(1, &ubo);
        usize = uvs.size() * sizeof(GLfloat);

        glBindVertexArray(vao);

        glBindBuffer(GL_ARRAY_BUFFER, ubo);
        glBufferData(GL_ARRAY_BUFFER, usize, uvs.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(2);

        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void Object::loadNormals(const std::vector<GLfloat>& normals) {
        glGenBuffers(1, &nbo);
        nsize = normals.size() * sizeof(GLfloat);

        glBindVertexArray(vao);

        glBindBuffer(GL_ARRAY_BUFFER, nbo);
        glBufferData(GL_ARRAY_BUFFER, nsize, normals.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(3);

        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void Object::render()
    {
        glBindTexture(GL_TEXTURE_2D, texture);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, (vsize/sizeof(GLuint))/3);
    }
}