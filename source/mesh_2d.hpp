#ifndef MESH_2D_HPP
#define MESH_2D_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <vector>

#include "engine.hpp"
#include "object.hpp"

namespace gfxcpp {

class mesh_2d : public object {
public:
	mesh_2d(engine& engine_ref);
	mesh_2d(engine& engine_ref, float vertices[], const size_t& size);
	mesh_2d(engine& engine_ref, const std::vector<float>& vertices);
	~mesh_2d();

	void update() override;
	void render() override;

private:
	engine& engine_ref;

	unsigned int vbo;
	unsigned int vao;

	size_t num_vertices;
};

} // namespace gfxcpp

#endif // MESH_2D_HPP
