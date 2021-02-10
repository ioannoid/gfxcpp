#pragma once

#include <vector>
#include <functional>
#include <map>

#include "Resource.hpp"

namespace Engine {
    class ResourceManager {
    public:
        ResourceManager();

        void addResource(const std::string& name, Resource& resource);
        Resource& getResource(const std::string& name) const;
    private:
        std::map<std::string, std::reference_wrapper<Resource>> resources;
    };
}