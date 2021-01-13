#include "Texture2D.hpp"

#include "stb_image.hpp"

namespace Engine {
    Texture2D::Texture2D() { }

    Texture2D::Texture2D(const char* texture) {
        glGenTextures(1, &this->texture);
        glBindTexture(GL_TEXTURE_2D, this->texture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

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
    }

    Texture2D::~Texture2D() { 
        glDeleteTextures(1, &texture);
    }
}