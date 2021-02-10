#include "ResourceManager.hpp"

namespace Engine {
        ResourceManager::ResourceManager() { }

        void ResourceManager:: addResource(const std::string& name, Resource& resource) {
            if(resources.contains(name)) throw -1;
            resources.at(name) = resource; 
        }

        Resource& ResourceManager::getResource(const std::string& name) const {
            if(!resources.contains(name)) throw -1;
            return resources.at(name);
        }
}