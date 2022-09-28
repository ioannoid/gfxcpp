#include "sprite.hpp"

using namespace gfxcpp;

sprite::sprite(engine& engine_ref) : engine_ref(engine_ref) {}

sprite::sprite(engine& engine_ref, float vertices[], const size_t& size)
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

sprite::sprite(engine& engine_ref, const std::vector<float>& vertices)
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

sprite::~sprite() {}

void sprite::update() {}

void sprite::render() {
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, num_vertices);
}
