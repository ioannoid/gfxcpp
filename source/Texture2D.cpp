 #include "Texture2D.hpp"

#include "stb_image.hpp"

namespace Engine {
    Texture2D::Texture2D() { 
        glGenTextures(1, &this->texture);
        glBindTexture(GL_TEXTURE_2D, this->texture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        GLubyte tmp[4] = {255, 255, 255, 255};

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1, 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, &tmp);
        glGenerateMipmap(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, 0);
    }

    Texture2D::Texture2D(const char* texture) {
        glGenTextures(1, &this->texture);
        glBindTexture(GL_TEXTURE_2D, this->texture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        int nrchannels;

        GLubyte* data = stbi_load(texture, &width, &height, &nrchannels, 0);
        if(data) {
            glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else {
            std::cout << "failed to load texture" << std::endl;
        }
        stbi_image_free(data);

        glBindTexture(GL_TEXTURE_2D, 0);
    }

    Texture2D::~Texture2D() { 
        if(texture) glDeleteTextures(1, &texture);
    }

    Texture2D& Texture2D::operator=(Texture2D&& texture2d) {
        texture = std::move(texture2d.texture);
        texture2d.texture = 0;
        width = std::move(width);
        height = std::move(height);
        return *this;
    }

    const int& Texture2D::getWidth() {
        return width;
    }
    const int& Texture2D::getHeight() {
        return height;
    }
}