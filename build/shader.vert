#version 430 core

layout (location = 0) in vec3 pos;
// layout (location = 2) in vec2 uvs;

// out vec2 textureCoords;

// uniform mat4 transform;
// uniform mat4 projection;

void main()
{
    // gl_Position = projection * transform * vec4(pos, 1.0f);
    gl_Position = vec4(pos, 1.0f);
    // textureCoords = uvs;
}
