#version 430 core

layout (location = 0) in vec3 pos;
//layout (location = 2) in vec2 uvs;

// uniform mat4 projection;
// uniform mat4 position;
// uniform mat4 rotation;
// uniform mat4 scale;

void main()
{
    //gl_Position = projection * position * rotation * scale * vec4(pos, 1.0f);
    gl_Position = vec4(pos, 1.0f);
}
