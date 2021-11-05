#version 330 core

layout (location = 0) in vec3 pos;
layout (location = 2) in vec2 uvs;

out vec2 textureCoords;

uniform mat4 projection;
uniform mat4 position;
uniform mat4 rotation;
uniform mat4 scale;

void main()
{
    gl_Position = projection * position * 
    mat4(
    vec4(1.0f, 0.0f, 0.0f, 0.0f), 
    vec4(0.0f, 1.0f, 0.0f, 0.0f), 
    vec4(0.0f, 0.0f, 1.0f, 0.0f), 
    vec4(31.0f*(gl_InstanceID%21), 31.0f*(floor(gl_InstanceID/21.0f)), 0.0f, 1.0f)) * rotation * scale * vec4(pos, 1.0f);
    
    textureCoords = uvs;
}