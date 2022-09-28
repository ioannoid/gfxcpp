#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <vector>

#include "engine.hpp"
#include "object.hpp"

namespace gfxcpp {

class sprite : public object {
public:
	sprite(engine& engine_ref);
	sprite(engine& engine_ref, float vertices[], const size_t& size);
	sprite(engine& engine_ref, const std::vector<float>& vertices);
	~sprite();

	void update() override;
	void render() override;

private:
	engine& engine_ref;

	unsigned int vbo;
	unsigned int vao;

	size_t num_vertices;
};

} // namespace gfxcpp

#endif // SPRITE_HPP
