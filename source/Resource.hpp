#pragma once

#include <string>

namespace Engine {
    class Resource {
    public:
        friend class ResourceManager;
        Resource();

    private:
        virtual void free() = 0;
    };
}