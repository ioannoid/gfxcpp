#include "mesh_2d.hpp"

using namespace gfxcpp;

mesh_2d::mesh_2d(engine& engine_ref) : engine_ref(engine_ref) {}

mesh_2d::mesh_2d(engine& engine_ref, float vertices[], const size_t& size)
	: engine_ref(engine_ref), num_vertices(size) {
	glGenBuffers(1, &vbo);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * size, vertices,
				 GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
						  static_cast<void*>(0));
	glEnableVertexAttribArray(0);
}

mesh_2d::mesh_2d(engine& engine_ref, const std::vector<float>& vertices)
	: engine_ref(engine_ref), num_vertices(vertices.size()) {
	glGenBuffers(1, &vbo);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(),
				 vertices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
						  static_cast<void*>(0));
	glEnableVertexAttribArray(0);
}

mesh_2d::~mesh_2d() {}

void mesh_2d::update() {}

void mesh_2d::render() {
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, num_vertices);
}
